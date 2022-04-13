document.onkeydown = animateKeys;

var colors = ['#FF0000','#00FFFF','#0000FF','#0000A0','#ADD8E6','#800080','#FFFF00','#00FF00','#FF00FF','#C0C0C0','#808080','#000000','#FFA500','#A52A2A','#800000','#008000','#808000'];

function animateKeys(event)
{
    var keyCode= event.keyCode;
    // event.which can be used as an alternative
    var c = String.fromCharCode(keyCode);

    var key = document.createElement("div");
    document.body.appendChild(key);

    key.style.position = "absolute";

    var randX = Math.floor(Math.random() * window.innerWidth);
    var randY = Math.floor(Math.random() * window.innerHeight);

    key.style.left = randX + 'px';
    key.style.top = randY + 'px';

    key.innerText = c;
    // key.textContent can be used as an alternative

    var color  = colors[Math.floor(Math.random()*colors.length)];
    key.style.color = color;

    key.style.transition = "all 0.5s linear 0s";
    key.style.left = key.offsetLeft -30 +'px';
    key.style.right = key.offsetRight -30 +'px';
    key.style.fontSize = "100px";
    key.style.opacity = 0;

    var sound = new Audio();
    sound.src = "audio.wav";
    sound.play();
}