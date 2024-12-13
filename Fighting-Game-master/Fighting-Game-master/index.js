
const canvas = document.querySelector('canvas');
const c = canvas.getContext('2d');

//resize canvas
const GRID_WIDTH = canvas.width = 1024;
const GRID_HEIGHT = canvas.height = 497;

//set background color
c.fillRect(0, 0, canvas.width, canvas.height);
//gravity
const gravity = 0.6;
const ground = canvas.height - 29;

const background = new Sprite({
    position: {
        x: 0,
        y: 0
    },
    imageSrc: "./img/bg.png"
});

const shop = new Sprite({
    position: {
        x: 700,
        y: canvas.height - 220
    },
    imageSrc: "./img/shop.png",
    scale: 1.5,
    frame: 6,
});

const player = FantasyWarrior;
const enemy = EvilWizard;
//for smoother movement because keyup event can stop player's movement
//create key object

const key = {
    a: {
        pressed: false,
    },
    d: {
        pressed: false,
    },
    ArrowRight: {
        pressed: false,
    },
    ArrowLeft: {
        pressed: false,
    }
}

decreasingTimer();
setDefaultPosition();
if (1 === 1) {
    animationLoop();
}

//animation loop
function animationLoop() {
    window.requestAnimationFrame(animationLoop);
    //redraw the background
    c.fillStyle = 'black';
    c.fillRect(0, 0, canvas.width, canvas.height);
    //draw background
    background.update();
    //draw shop
    shop.update();
    c.fillStyle = 'rgba(255, 255, 255, 0.14)'
    c.fillRect(0, 0, canvas.width, canvas.height);
    //update animation
    player.update();
    enemy.update();
    //move left or right and check what is the current key is pressed for precise animation
    player.velocity.xVec = 0;
    enemy.velocity.xVec = 0;
    movement();
    detectCollision();
    checkOnGround();
    idleState();
    jumpMovement();

    function checkOnGround() {
        if (player.position.y + player.height >= ground) {
            player.onGround = true;
        }
        if (player.position.y + player.height < ground) {
            player.onGround = false;
        }
        if (enemy.position.y + enemy.height >= ground) {
            enemy.onGround = true;
        }
        if (enemy.position.y + enemy.height < ground) {
            enemy.onGround = false;
        }
    }
    //detecting when player is acellerating up or down
    function jumpMovement() {
        if (player.velocity.yVec > 0) {
            player.switchSprites('fall');
        }
        if (player.velocity.yVec < 0) {
            player.switchSprites('jump');
        }
        if (enemy.velocity.yVec > 0) {
            enemy.switchSprites('fall');

        }
        if (enemy.velocity.yVec < 0) {
            enemy.switchSprites('jump');
        }
    }
    function idleState() {
        if (player.velocity.yVec === 0
            && key.a.pressed === false
            && key.d.pressed === false
            && player.isAttacking === false
            && player.health > 0) {
            player.switchSprites('idle');
        }
        if (enemy.velocity.yVec === 0
            && key.ArrowRight.pressed === false
            && key.ArrowLeft.pressed === false
            && enemy.isAttacking === false
            && enemy.health > 0) {
            enemy.switchSprites('idle');
        }
    }

    function movement() {
        //player's movement         
        if (key.a.pressed && player.lastKey === 'a') {
            player.velocity.xVec = -5;
            player.switchSprites('move'); // set player current image to run
        }
        else if (key.d.pressed && player.lastKey === 'd') {
            player.velocity.xVec = 5;
            player.switchSprites('move');
        }

        //enemy's movement       
        if (key.ArrowRight.pressed && enemy.lastKey === 'ArrowRight') {
            enemy.velocity.xVec = 5;
            enemy.switchSprites('move');
        }
        else if (key.ArrowLeft.pressed && enemy.lastKey === 'ArrowLeft') {
            enemy.velocity.xVec = -5;
            enemy.switchSprites('move');
        }

    }
    //set the knockback depend on the attack style
    function setKnockback({ looking, attack, fighter }) {
        //attack is the attack skills (1, 2, ...)
        if (attack === 1) {
            fighter.knockback = 1024 / 15;
            fighter.performKnockback(looking);
            return;
        }
        if (attack === 2) {
            fighter.knockback = 1024 * 2 / 15;
            fighter.performKnockback(looking);
            return;
        }
    }
    function takeHit({attacker, target}) {
        attacker.isAttacking = false;
        target.health -= attacker.damage;
    }
    function detectCollision() {
        //player's attackBox collisions
        if (rectangularCollision({
            rect1: player,
            rect2: enemy
        })
            && player.isAttacking
        ) {
            enemy.switchSprites('takeHit');
            setKnockback({
                looking: player.looking,
                attack: player.attackNumber,
                fighter: enemy
            }); //set knockback
            player.isAttacking = false;
            enemy.health -= player.damage;
            // document.querySelector('#enemyHealth').style.width = enemy.health + '%';
            gsap.to('#enemyHealth', {
                width: enemy.health + '%'
            })
        }
        //enemy's attackBox collisions
        else if (rectangularCollision({
            rect1: enemy,
            rect2: player
        })
            && enemy.isAttacking
        ) {
            player.switchSprites('takeHit');
            setKnockback({
                looking: enemy.looking,
                attack: enemy.attackNumber,
                fighter: player
            });
            takeHit({
                attacker: enemy,
                target: player
            })
            // document.querySelector('#playerHealth').style.width = player.health + '%';
            gsap.to('#playerHealth', {
                width: player.health + '%'
            })
        }
        // end game base of health
        if (player.health <= 0) {
            changeHTML({
                text: 'player 2 wins',
                timerId: timerId
            })
        } else if (enemy.health <= 0) {
            changeHTML({
                text: 'player 1 wins',
                timerId: timerId
            })
        }
    }
}




window.addEventListener('keyup', (event) => {
    if (!player.dead && !player.knockbackState) {
        switch (event.key) {
            //player
            case 's':
                player.attack(1);
                break;
            //  case ' ':
            //      player.attack(2);
            //      break;           
            case 'd': key.d.pressed = false; break;
            case 'a': key.a.pressed = false; break;
        }
    }
    if (!enemy.death && !enemy.knockbackState) {
        //enemy
        switch (event.key) {
            case 'ArrowDown':
                enemy.attack(1);
                break;
            //  case 'Control': 
            //     enemy.attack(2);
            //     break;       
            case 'ArrowRight': key.ArrowRight.pressed = false; break;
            case 'ArrowLeft': key.ArrowLeft.pressed = false; break;
        }
    }
})
window.addEventListener('keydown', (event) => {
    if (!player.dead && !player.knockbackState) {
        switch (event.key) {
            //player's key
            case 'd':
                key.d.pressed = true;
                player.looking = 'right';
                player.lastKey = 'd';
                break;
            case 'a':
                key.a.pressed = true;
                player.looking = 'left';
                player.lastKey = 'a';
                break;
            case 'w':
                player.jump();
                break;
        }
    }
    if (!enemy.dead && !enemy.knockbackState) {
        switch (event.key) {
            //enemy's key'
            case 'ArrowRight':
                key.ArrowRight.pressed = true;
                enemy.looking = 'right';
                enemy.lastKey = 'ArrowRight';
                break;
            case 'ArrowLeft':
                key.ArrowLeft.pressed = true;
                enemy.looking = 'left';
                enemy.lastKey = 'ArrowLeft';
                break;
            case 'ArrowUp':
                enemy.jump();
                break;
        }
    }
});
