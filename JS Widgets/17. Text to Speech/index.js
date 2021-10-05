function checkCompatability(){
    if(!('speechSynthesis' in window)){
        alert('Your Browser is not supported. If Google chrome, please upgrade !!!');
    }
};
checkCompatability();

var voiceOptions = document.getElementById('voiceOptions');
var volumeSlider = document.getElementById('volumeSlider');
var rateSlider = document.getElementById('rateSlider');
var pitchSlider = document.getElementById('pitchSlider');
var myText = document.getElementById('myText');

var voiceMap = [];

function loadVoices(){
    var voices = speechSynthesis.getVoices();
    for(var i=0; i<voices.length; i++)
    {
        var voice = voices[i];
        var option = document.createElement('option');
        option.value = voice.name;
        option.innerHTML = voice.name;
        voiceOptions.appendChild(option);
        voiceMap[voice.name] = voice;
    };
};

window.speechSynthesis.onvoiceschanged = function(e){
    loadVoices();
};

function speak(){
    var msg = new SpeechSynthesisUtterance();
    msg.volume = volumeSlider.value;
    msg.voice = voiceMap[voiceOptions.value];
    msg.rate = rateSlider.value;
    msg.pitch = pitchSlider.value;
    msg.text = myText.value;
    window.speechSynthesis.speak(msg);
};