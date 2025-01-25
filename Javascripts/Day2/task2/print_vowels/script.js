// Count Vowels 
// Description: Write a function that takes a string as input and returns the number of vowels (a,    
// e, i, o, u) in the string.

let quote=new String(prompt("Enter the quote: "));
let countVowel=function(quote){
    let counter=0;
    for(let i=0;i<quote.length;i++){
        if(quote[i]=='a'||quote[i]=='e'||quote[i]=='i'||quote[i]=='o'||quote[i]=='u'){
            counter++;
        }
    }
        return counter;
}
console.log(`Number of vowels:${countVowel(quote.toLowerCase())} `);
