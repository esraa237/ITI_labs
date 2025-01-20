// Capitalize Words 
// Description: Write a function that takes a string as input and returns a new string where the 
// first letter of each word is capitalized. 
//
let input=new String(prompt("Enter String: "));
let capitalize=function(input){
    let result=input[0].toUpperCase();
    for(let i=1;i<input.length;i++){
        if(input[i-1]==' '){
            result+=input[i].toUpperCase();
        }
        else{
            result+=input[i];
        }
    }
    return result;
}
console.log(`Input:${input}`);
console.log(`Output: ${capitalize(input)}`);

