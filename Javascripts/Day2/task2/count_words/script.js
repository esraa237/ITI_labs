// Task4: Count Words 
// Description: Write a function that takes a string as input and returns the number of words in 
// the string. 


let countWords=function(input){
    let counter=1;
    let trimedInput=input.trim();
    for(let i=0;i<trimedInput.length;i++){
        if(trimedInput[i-1]==' '&&trimedInput[i]!=' '){
            counter++;
        }
    }
    return counter;
}
let input=new String(prompt("Enter String: "));
console.log(`Count of Words:${countWords(input)}`);