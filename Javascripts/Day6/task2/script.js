// 4- write function startSliding(ImgObject) which takes the image 
// Object to be slide on the page , and start changing the image 
// every second  
// to be professional :don’t make timer ID global return it from 
// sliding function. 
// then write another function that stop image sliding   
// stopSliding(timerID) which stop sliding the image. 
// Now call these functions on console to control image sliding on 
// the page. 
let imagesSrc=["./images/1.jpg","./images/1182.png","./images/3.jpg","./images/4.jpg","./images/5.jpg","./images/6.jpg","./images/7.jpg","./images/8.jpg"];
let selectImages=document.querySelectorAll("img");

let startSliding=function(ImgObject){
    let timerID= setInterval(function(){
        const randomIndex = Math.floor(Math.random() * imagesSrc.length);
        ImgObject.src=imagesSrc[randomIndex];
    },1000);
    return timerID;
}
let stopSliding=function(timerId){
    clearInterval(timerId);
}

let timerid1=startSliding(selectImages[0]);
let timerid2=startSliding(selectImages[1]);
setTimeout(function(){
    stopSliding(timerid1);
    stopSliding(timerid2);
},5000);