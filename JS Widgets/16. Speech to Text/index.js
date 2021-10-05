var r = document.getElementById('result');

function startConverting()
{
    if('webkitSpeechRecognition' in window)
    {
        var speechRecognizer = new webkitSpeechRecognition(); 
        speechRecognizer.continuous = true;
        speechRecognizer.interimResults = true;
        speechRecognizer.lang = 'en-IN';
        speechRecognizer.start();

        var finalTranscripts = '';

        speechRecognizer.onresult = function(event)
        {
            var interimTranscripts = '';
            for(var i=event.resultIndex; i<event.results.length; i++)
            {
                var transcript = event.results[i][0].transcript;
                transcript.replace("\n", "<br>");
                if(event.results[i].isFinal){
                    finalTranscripts+= transcript;
                }
                else{
                    interimTranscripts+=transcript;
                }
            }
            r.innerHTML = finalTranscripts + '<span style = "color:#999">' + interimTranscripts + '</span>';

        };

        speechRecognizer.onerror = function(event)
        {

        };
    }
    else
    {
        r.innerHTML = "Your Browser is not supported. If Google Chrome please upgrade... ";
    }
}

