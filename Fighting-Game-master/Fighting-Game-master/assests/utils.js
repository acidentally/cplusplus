//detect collisions of attackBox
function rectangularCollision({ rect1, rect2 }) {
    return (
        rect1.attackBox.position.x + rect1.attackBox.width >=
        rect2.hitBox.position.x &&
        rect2.hitBox.position.x + rect2.hitBox.width >=
        rect1.attackBox.position.x &&
        rect1.attackBox.position.y + rect1.attackBox.height >=
        rect2.hitBox.position.y &&
        rect1.attackBox.position.y <= rect2.hitBox.position.y + rect2.hitBox.height
    )
}
//timer
let timer = 120;
let timerId;

function changeHTML({ text, timerId }) {
    clearTimeout(timerId); //stop the timer
    document.querySelector('#displayTieText').innerHTML = "<span style=color:Black>"+ text + "</span>";
    document.querySelector('#displayTieText').style.display = 'flex';
}
function decreasingTimer() {
    if (timer > 0) {
        timerId = setTimeout(() => {
            decreasingTimer();
        }, 1000)
        timer--;
        document.querySelector('#timer').innerHTML = timer;
    }
    if (timer === 0) {
        if (player.health === enemy.health) {
            changeHTML({
                text: 'Tie',
                timerId: timerId
            })

        }
        else if (player.health > enemy.health) {
            changeHTML({
                text: 'Player 1 wins',
                timerId: timerId
            })
        }
        else if (player.health < enemy.health) {
            changeHTML({
                text: 'Player 2 wins',
                timerId: timerId
            })
        }
    }
}
function setDefaultPosition() {
    enemy.looking = 'left';
    enemy.position = {
        x: 1024-65,
        y: 0
    }
    player.looking = 'right';
    player.position = {
        x:0,
        y:0
    }
}