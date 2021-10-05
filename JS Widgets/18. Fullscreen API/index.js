function viewPage(){
    var el = document.body;
    toggleFullScreen(el);
}

function viewImage(){
    var el = document.getElementById('myImage');
    toggleFullScreen(el);
}

function toggleFullScreen(el){
    if(document.fullscreenElement || document.mozFullScreenElement || document.webkitFullScreenElement || document.msFullScreenElement){
        if(document.exitFullscreen){
            document.exitFullscreen();
        }
        else if(document.mozCancelFullScreen){
            document.mozCancelFullScreen();
        }
        else if(document.webkitExitFullscreen){
            document.webkitExitFullscreen();
        }
        else if(document.msExitFullscreen){
            document.msExitFullscreen();
        }
    }
    else{
        if(document.documentElement.requestFullscreen){
            el.requestFullscreen();
        }
        else if(document.documentElement.mozRequestFullScreen){
            el.mozRequestFullScreen();
        }
        else if(document.documentElement.webkitRequestFullScreen){
            el.webkitRequestFullScreen();
        }
        else if(document.documentElement.msRequestFullScreen){
            el.msRequestFullScreen();
        }
    }
}