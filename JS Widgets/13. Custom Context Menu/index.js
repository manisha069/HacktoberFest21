
window.onclick = hideContextMenu;
window.onkeydown = listenKeys;
var ContextMenu = document.getElementById('contextMenu');

function showContextMenu(){
    ContextMenu.style.display = 'block';
    ContextMenu.style.left = event.clientX + 'px';
    ContextMenu.style.top = event.clientY + 'px';
    return false;
}

function hideContextMenu(){
    ContextMenu.style.display = 'none';
}

function listenKeys(event){
    var keyCode = event.which || event.keyCode;
    if(keyCode==27){
        hideContextMenu();
    }
}