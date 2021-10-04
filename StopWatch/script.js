var seconds=00;
var tens=00;
var mins=00;

var tens1=document.getElementById('tens');
var seconds1=document.getElementById('seconds');
var mins1=document.getElementById('mins');

var btnstart = document.getElementById('start');
var btnstop = document.getElementById('stop');
var btnreset = document.getElementById('reset');
var interval;   //to store timer values

function startTimer(){
    tens++;

    if(tens<=9){
        tens1.innerHTML = "0" + tens;
    }
    if(tens>9){
        tens1.innerHTML = tens;}
    if(tens>99){
        seconds++;
        seconds1.innerHTML = "0" + seconds;
        tens = 0;
       tens1.innerHTML = "0" + 0;
    }
    if(seconds > 9){
        seconds1.innerHTML = seconds;
    }
    if(seconds  > 59){
        mins++;
        mins1.innerHTML = "0" + mins;
        seconds = 0;
        seconds1.innerHTML = "0" + 0;
    }
    if(mins > 9){
        mins1.innerHTML = mins;
    }
    
}

btnstart.onclick = function() {interval = setInterval(startTimer, 10);};
    
 

btnstop.onclick = function(){
    clearInterval(interval);
};

btnreset.onclick = function(){
    clearInterval(interval);
    tens = "00";
    seconds = "00";
    mins = "00";
    seconds1.innerHTML = seconds;
    tens1.innerHTML = tens;
    mins1.innerHTML = mins;
};





