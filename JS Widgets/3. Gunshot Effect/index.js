window.onclick = gunshot;
 
	function gunshot(event){
		// 1. Clone the image element
		var el = document.getElementById('gunshot').cloneNode();
		// 2. Append it to the HTML document
		document.body.appendChild(el);
		// 3. Remove the display:none style
		el.style.display = '';
		// 4. Show image at the mouse coordinates
		el.style.left = event.clientX - (el.offsetWidth / 2) + 'px';
		el.style.top = event.clientY - (el.offsetHeight / 2) + 'px';
		// 5. Add sound effect
		var shotSound = new Audio();
		shotSound.src = "Gunshot_audio.mp3";
		shotSound.play();
	}
 