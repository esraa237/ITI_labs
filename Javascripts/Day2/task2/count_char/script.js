// Task3: Count Character Occurrences 
// Description: Write a function that takes a string and a character as input and returns the 
// number of occurrences of that character in the string. 

let countChar=function(input,char){
    let counter=0;
    if(input.includes(character)){
        for(let i=0;i<input.length;i++){
            if(input[i]==character){
                counter++;
            }
        }
    }
    return counter;
}

let input=new String(prompt("Enter String: "));
let character=prompt("Enter Character: ");
console.log(`the count of character occurrences:${countChar(input,character)}`);