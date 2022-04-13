var imageContainer = document.getElementById('imageContainer');
var images = ['img1.jpg', 'img2.jpg', 'img3.jpg'];
var totalPics = images.length;
var currentImage = 0;

function changeImage() 
{
	var imageSource = images[currentImage];
	currentImage = currentImage + 1 == totalPics ? 0 : currentImage + 1;
	imageContainer.innerHTML = '<img src="' + imageSource + '" width="420" height="240" />';
	setTimeout(changeImage, 5000);
}

changeImage();