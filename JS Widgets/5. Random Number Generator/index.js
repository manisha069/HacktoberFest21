function generateRandomNumber(){
    var min = parseInt(document.getElementById('min').value);
    var max = parseInt(document.getElementById('max').value);
    
    var rand = Math.floor(Math.random() * (max - min + 1)) + min;
    document.getElementById('display').innerText = rand;
}