//1- Using document object method on the lecture’s HTML page
// a- Find all images in page by two ways (document default 
//     collection and document methods). 
let allImages=document.querySelectorAll("img");
document.getElementsByTagName("img");

// b- Find all options for City drop down list. 
document.querySelectorAll("select option");

// c- Find all rows for second table in page
document.querySelectorAll(".bPink tr");

// d- Find all elements that contain class name fontBlue and BGrey. 
document.querySelectorAll(".fontBlue.bGrey");

// 2- Do the following actions on the following HTML elements 
// a- Get first anchor inside the second table then change its’ href 
// property to training.com and it’s text to “Training” 

let firstAncor=document.querySelector(".bPink a");
firstAncor.innerText="Training";
firstAncor.href="training.com";

// b- Find all images and change its borders to : solid pink 2px  
for(let i=0;i<allImages.length;i++){
    allImages[i].classList.add("allImages");
}

// c- Find all checkboxes (checked) in userData form and alert 
// their values 
let getCheckboxes=document.querySelectorAll("input[name=hoppy]:checked");
for(let i=0;i<getCheckboxes.length;i++){
    console.log(getCheckboxes[i].value);
    // window.alert(`${getCheckboxes[i].innerText} : ${getCheckboxes[i].value}`);
}

// d- Find element with id value “example” then change it’s 
// background color to pink  

document.querySelector("#example").style.backgroundColor="pink";

// 3- Display the date with time on the document title (which 
//     changed every second to show time with date). 
//     Note: use .toLocalString() method of the Date Object. 

let date=new Date();
let datetitle=setInterval(() => {
     document.title=date.toLocaleString();
     date=new Date();
     //  document.title="the";
},1000);

