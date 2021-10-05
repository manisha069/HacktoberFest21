var ball = document.createElement("img");
document.body.appendChild(ball);

ball.src = "image.png";
ball.style.width = "80px";
ball.style.left = "0px";
ball.style.top = "0px";
ball.style.position = "absolute";

var boundX = window.innerWidth;
var boundY = window.innerHeight;

var speedx = 10;
var speedy = 10;
var newposx = 0;
var newposy = 0;

function screensaver () {
    newposx += speedx;
    newposy += speedy;

    if(newposx + 80 > boundX || newposx < 0){
        speedx *= -1;
    }

    if(newposy + 80 > boundY || newposy < 0){
        speedy *= -1;
    }

    ball.style.left = newposx + 'px';
    ball.style.top = newposy + 'px';

    setTimeout(screensaver, 20);
}

screensaver();