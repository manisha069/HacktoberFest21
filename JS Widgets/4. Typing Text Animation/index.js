var string = " Hi! I am Akshat Aggarwal. I am currently pursuing B.Tech in Information Technology(IT) from Netaji Subhas University of Technology(NSUT). How are you doing?"

var strArray = string.split("");

function animate()
{
    if(strArray.length>0)
    {
        document.getElementById('display').innerHTML += strArray.shift();
    }
    else{
        return;
    }
    setTimeout(animate,50);
}
animate();