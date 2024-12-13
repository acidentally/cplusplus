//player and the enemy class
class Sprite {
    //position and velocity is an object
    constructor({ position, imageSrc, scale = 1, frame = 1, offset = { x: 0, y: 0 } }) {
        this.position = position;
        this.height = 150;
        this.width = 35;
        this.image = new Image();
        this.image.src = imageSrc;
        this.scale = scale;
        this.maxFrame = frame;
        this.currentFrame = 0;
        this.frameElapsed = 0;
        this.frameHold = 10;
        this.offset = offset; //reposition the sprite if there are spaces around it
    }

    //draw the default img
    draw() {
        //draw Image with args (image , the crop.x , ..y, .. width, ..height, image.x, image y
        //                         .. width, ..height) what a powerful method for image resizing!
        c.drawImage(this.image,
            // upon on increasing the currentFrame, the x pos of the crop is also updated
            this.currentFrame * (this.image.width / this.maxFrame),
            0,
            this.image.width / this.maxFrame,
            this.image.height,
            this.position.x - this.offset.x,
            this.position.y - this.offset.y,
            (this.image.width / this.maxFrame) * this.scale,
            this.image.height * this.scale);
    }
    //draw the flipped img
    drawFlip() {
        c.save();
        c.scale(-1, 1);
        c.drawImage(this.image,
            // upon on increasing the currentFrame, the x pos of the crop is also updated
            this.currentFrame * (this.image.width / this.maxFrame),
            0,
            this.image.width / this.maxFrame,
            this.image.height,
            -(this.position.x - this.offset.x) - ((this.image.width / this.maxFrame) * this.scale), // instead of x now we draw -x-width
            this.position.y - this.offset.y,
            (this.image.width / this.maxFrame) * this.scale,
            this.image.height * this.scale);
        c.setTransform(1, 0, 0, 1, 0, 0);
    }
    animation() {
        this.frameElapsed++;
        if (this.frameElapsed % this.frameHold === 0) {
            //because currentFrame starts with 0 so we - 1 
            if (this.currentFrame < this.maxFrame - 1) {
                this.currentFrame++;
            } else {
                this.currentFrame = 0;
            }

        }
    }
    update() {
        this.draw();
        this.animation();
    }
}
class Fighter extends Sprite {
    //position and velocity is an object
    constructor({
        position,
        velocity,
        looking,
        imageSrc,
        scale = 1,
        frame = 1,
        offset = { x: 0, y: 0 },
        attackBox = { offset: { x, y }, width: undefined, height: undefined },
        hitBox = { offset: { x, y }, width: undefined, height: undefined },
        sprites //decide sprite for the character
    }) {
        super({
            position,
            imageSrc,
            scale,
            frame,
            offset
        }); // call the constructor of the parent class
        //animatiion
        this.currentFrame = 0;
        this.frameElapsed = 0;
        this.frameHold = 10;
        //player properties
        this.velocity = velocity;
        this.lastKey; //for smoother movement
        this.height = 150;
        this.width = 50;
        this.attackBox = {
            position: {
                x: this.position.x,
                y: this.position.y
            },
            offset: attackBox.offset,
            width: attackBox.width,
            height: attackBox.height
        }
        this.hitBox = {
            position: {
                x: this.position.x,
                y: this.position.y
            },
            offset: hitBox.offset,
            width: hitBox.width,
            height: hitBox.height
        }
        //facing 
        this.facing = {
            position: {
                x: this.position.x,
                y: this.position.y + 30,
            },
        },
            this.looking = looking;

        //fighter varibles
        this.doubleJump = false;
        this.isAttacking = false;
        this.onGround = true;
        this.health = 100;
        this.damage;
        this.dead = false;
        //sprites and update image using the current sprite (run, idle, etc)
        this.sprites = sprites
        //loop through sprites
        for (const sprite in sprites) {
            //loop through sprite object 
            sprites[sprite].image = new Image();
            sprites[sprite].image.src = sprites[sprite].imageSrc;
        }
        //attack varibles
        this.attackDelay = this.sprites.attack1.attackDelay;
        this.attackDelay = this.sprites.attack2.attackDelay;
        this.knockback = 0;
        this.knockbackState = false;
        this.attackNunber = 1;
    }
    drawattackBox() {
        c.fillStyle = 'red';
        c.fillRect(this.attackBox.position.x, this.attackBox.position.y, this.attackBox.width, this.attackBox.height);
    }
    //update animation
    checkCollision() {
        if (this.position.y + this.height + this.velocity.yVec >= ground) {
            this.velocity.yVec = 0;
            this.position.y = 318; //set y position to hit the ground
        } else {
            this.velocity.yVec += gravity; //add gravity for acceleration
        }
        //stay in battle
        if (this.position.x + this.width > canvas.width) {
            this.position.x = canvas.width - this.width;
        }
        if (this.position.x < 0) {
            this.position.x = 0;
        }
    }
    move() {
        //sprites pos
        this.position.y += this.velocity.yVec;
        this.position.x += this.velocity.xVec;
        this.facing.position.x += this.velocity.xVec;
        this.facing.position.y += this.velocity.yVec;
        //hitBox pos
        this.hitBox.position.y = this.position.y + this.hitBox.offset.y;
        this.hitBox.position.x = this.position.x + this.hitBox.offset.x;
    }
    jump() {
        if (this.doubleJump === false && this.onGround) // the value double is current false
        {
            this.velocity.yVec = -10;
            this.doubleJump = true;
        }
        else if (this.doubleJump && !this.onGround) //now its true
        {
            this.velocity.yVec = -15;
            this.doubleJump = false;
        }
        setTimeout(() => {
            this.doubleJump = false;
        }, 340);
    }
    
    attack(number) {
        this.attackNumber = number; //set the attack style for knockback
        switch(number) {
            case 1: 
                this.performAttack('attack1'); 
                break;
            case 2: 
                this.performAttack('attack2'); 
                break;
        }
    }
    performAttack(attkSprites) {
        //changing attack sprites
        this.switchSprites(attkSprites); //switch to attack sprites with damage and animation
            
        if (this.currentFrame === 0) { //only perform the attack once every hit preventing spammers
            //setAttacking            
            //set the animation correctly
            setTimeout(() => {
                this.isAttacking = true;
                //attack for a period of time
                setTimeout(() => {                   
                    this.isAttacking = false;
                }, 50);
            }, this.attackDelay)

        }
    }
    performKnockback(opponentLooking) {        
        //knock the fighter back depend on the direction of the attack's sprite
        if(opponentLooking === 'left') {           
            //set the velocity of the knockback
            if(this.knockback >= 0) {
                this.knockback *= -1; //revert if the knockback is positive
            }
            this.knockbackState = true;
            //perform the knockback action 10 times
            for(let i = 0; i < 10; i++) {
                setTimeout(() => {
                    if(i < 5) {
                        this.position.y += -10; // knock upwards a little bit
                    }
                    this.position.x += (this.knockback/10); 
                }, 30*i)             
            }
            this.knockbackState = false;       
        }
        else if(opponentLooking === 'right') {           
            //set the velocity of the knockback
            if(this.knockback <= 0) {
                this.knockback *= -1;                         
            } 
            this.knockbackState = true; 
            //perform the knockback action 10 times    
            for(let i = 0; i < 10; i++) {
                setTimeout(() => {
                    if(i < 5) {
                        this.position.y += -10; // knock upwards a little bit
                    }
                    this.position.x += (this.knockback/10); 
                }, 30*i)                             
            }         
            this.knockbackState = false;
        }
    }
    
    checkDeath() {
        if (this.health > 0) {
            return;
        }
        else {
            this.switchSprites('death');
        }
    }
    
    updateattackBoxPos() {
        if (this.isAttacking) {
            this.attackBox.position.x = this.position.x + this.attackBox.offset.x;
            this.attackBox.position.y = this.position.y + this.attackBox.offset.y;
        }
    }
    //flip the attackBoxes
    updateattackBoxFacing() {
        if (this.looking === 'right') {
            this.attackBox.offset.x = 50; // will be more or less depend on player's atributes
        }
        if (this.looking === 'left') {
            this.attackBox.offset.x = -this.attackBox.width;
        }
    }
    // override when fighter get hit
    switchSprites(sprite) {
        if (this.image === this.sprites.death.image
            && this.currentFrame === this.sprites.death.frame - 1) {
            this.dead = true;
            return;
        }
        //if attacking, then no longer call changing sprites in order to prevent weird animations
        if (this.image === this.sprites.attack1.image
            && this.currentFrame < this.sprites.attack1.frame - 1) {
            return;
        }
        if (this.image === this.sprites.attack2.image
            && this.currentFrame < this.sprites.attack2.frame - 1) {
                return;
            }
        // override when fighter get hit, death
        if (this.image === this.sprites.takeHit.image
            && this.currentFrame < this.sprites.takeHit.frame - 1) {
            return;
        }

        switch (sprite) {
            case 'idle':
                if (this.image !== this.sprites.idle.image) {
                    this.image = this.sprites.idle.image;
                    this.maxFrame = this.sprites.idle.frame;
                    //set current frame back to 0
                    this.currentFrame = 0;
                    this.frameHold = this.sprites.idle.frameHold;
                }
                break;
            case 'move':
                if (this.image !== this.sprites.move.image) {
                    this.image = this.sprites.move.image;
                    this.maxFrame = this.sprites.move.frame;
                    this.currentFrame = 0;
                    this.frameHold = this.sprites.move.frameHold;
                }
                break;
            case 'jump':
                if (this.image !== this.sprites.jump.image) {
                    this.currentFrame = 0;
                    this.image = this.sprites.jump.image;
                    this.maxFrame = this.sprites.jump.frame;
                    this.frameHold = this.sprites.jump.frameHold;
                }
                break;
            case 'fall':
                if (this.image !== this.sprites.fall.image) {
                    this.currentFrame = 0;
                    this.image = this.sprites.fall.image;
                    this.maxFrame = this.sprites.fall.frame;
                    this.frameHold = this.sprites.fall.frameHold;
                }
                break;
            case 'attack1':
                if (this.image !== this.sprites.attack1.image) {
                    this.currentFrame = 0;
                    this.image = this.sprites.attack1.image;
                    this.maxFrame = this.sprites.attack1.frame;
                    this.frameHold = this.sprites.attack1.frameHold;
                    this.damage = this.sprites.attack1.damage;
                }
                break;
            case 'attack2': 
                if(this.image !== this.sprites.attack2.image) {
                    this.currentFrame = 0;
                    this.image = this.sprites.attack2.image;
                    this.maxFrame = this.sprites.attack2.frame;
                    this.frameHold = this.sprites.attack2.frameHold;
                    this.damage = this.sprites.attack2.damage;
                }
                break;
            case 'takeHit': {
                if (this.image !== this.sprites.takeHit.image) {
                    this.currentFrame = 0;
                    this.image = this.sprites.takeHit.image;
                    this.maxFrame = this.sprites.takeHit.frame;
                    this.frameHold = this.sprites.takeHit.frameHold;
                }
                break;
            }
            case 'death': {
                if (this.image !== this.sprites.death.image) {
                    this.currentFrame = 0;
                    this.image = this.sprites.death.image;
                    this.maxFrame = this.sprites.death.frame;
                    this.frameHold = this.sprites.death.frameHold;
                }
                break;
            }
        }
    }
    drawFighter() {
        //draw the image base on the looking
        if (this.looking === 'right') {
            this.draw();
        }
        else if (this.looking === 'left') {
            this.drawFlip();
        }
    }

    update() {

        if (!this.dead) this.animation();
        //this.drawattackBox();
        this.updateattackBoxFacing();
        this.checkCollision();
        this.drawFighter();
        this.move();
        this.updateattackBoxPos();
        this.checkDeath();
        //c.strokeStyle = 'black'
        // c.strokeRect(this.hitBox.position.x, this.hitBox.position.y, this.hitBox.width, this.height);
    }
}

