let input = document.getElementById("screen"); 
buttons = document.querySelectorAll("button");
let screenval = '';
for(item of buttons){
    item.addEventListener("click", e => {
        buttontext = e.target.innerText;
        if(buttontext=="+"){
            (input.value)+=buttontext;
        }
        else if(buttontext=="x"){
            buttontext = '*';
            (input.value)+=buttontext;
        }
        else if(buttontext=="C"){
            input.value = "";
        }
        else if(buttontext=="Back"){
            setCaretPosition(input, input.value.length);
            function setCaretPosition(ctrl, pos) {
                if (ctrl.setSelectionRange) {
                  ctrl.focus();
                  ctrl.setSelectionRange(pos, pos-1);
                }
            }
        }
        else if(buttontext=="Sqrt"){
            screenval = Math.sqrt(eval(input.value));
            input.value = screenval;
        }
        else if(buttontext=="sin"){
            screenval = Math.sin((180*eval(input.value))/Math.PI);
            input.value = screenval;
        }
        else if(buttontext=="cos"){
            screenval = Math.cos(eval(input.value));
            input.value = screenval;
        }
        else if(buttontext=="tan"){
            screenval = Math.tan(eval(input.value));
            input.value = screenval;
        }
        else if(buttontext=="ln"){
            screenval = Math.log(eval(input.value));
            input.value = screenval;
        }
        else if(buttontext=="%"){
            screenval = eval(input.value)*100;
            input.value = screenval;
        }
        else if(buttontext=="="){
            screenval = eval(input.value);
            input.value = screenval;
        }
        else if(buttontext=="Del"){
            input.value = (input.value).substr(0,(input.value).length-1);
        }
        else {
            (input.value)+=buttontext;
        }
    })
}