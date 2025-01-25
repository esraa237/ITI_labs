//Task1
//10. Create an array called students with the names of the seven 
// students (write down any names). 
// names=[“Elina”,”ahmed”,”Mona”,”eman”,”Ali”,”maha”,”zyad”] 

let students=["Elina","ahmed","Mona","eman","Ali","maha","zyad"] ;
console.log(students);

//Task2
// 11. sort names Ascending
console.log("Sort with ASCI"); 
students.sort();
console.log(students);

console.log("Sort with letters ignoring upper and lower case")
students.sort((a,b)=>{
    if(a.toLowerCase()>b.toLowerCase())return 1;
    else if(a.toLowerCase()<b.toLowerCase()) return -1;
    else return 0;
    });
console.log(students);

//Task3
// 12. create a function takes a string as input and return string pascal 
// case. 

const convertToPascal=(input)=>{
    let trimmedInput=input.toLowerCase().trim();
    let convertedInput=trimmedInput[0].toUpperCase();
    for(let char=1;char<trimmedInput.length;char++){
        if(trimmedInput[char-1]==" " && trimmedInput[char]!=" "){
            convertedInput+=trimmedInput[char].toUpperCase();
        }
        else if(trimmedInput[char]==" "){
            continue;
        }
        else {
            convertedInput+=trimmedInput[char];
        }
    }
    return convertedInput;
}
console.log(convertToPascal("esraa tark mohammed foda"));
//charAt(index) represents the character at index
//slice(indexStart) returb A new string containing the extracted section of the string.
const toPascal=(input)=>{
    let convertedInput=input
    .toLowerCase()
    .trim()
    .split(" ")
    .map((word)=>word[0].toUpperCase()+word.slice(1))
    .join("");
    return convertedInput;
}
console.log(toPascal("esraa tark mohammed foda"));

//Task4
//13. Use previous function to convert students’ names array to 
// PascalCase  (Note:map) 
let convertNamesToPascal=()=>students.map(toPascal);
console.log(convertNamesToPascal());

//Task5
//14.Find student with 4 or more letters. (search find, findIndex) 

//return all students with 4 or more letters
let filterStudents=(students)=>students.filter((studentName)=>studentName.length>=4);
console.log(filterStudents(students));

//return the first name of student with 4 or more letters
//find==> return element
let findStudent=(students)=>students.find((student)=>(student.length)>=4);
console.log(findStudent(students))

//return the first index of name of student with 4 or more letters
//findIndex==> return index of element
let findIndexofStudent=(students)=>students.findIndex((student)=>(student.length)>=4);
console.log(`${findIndexofStudent(students)}:${students[findIndexofStudent(students)]}`)

//Task6
// 15. Combine the students array with the grades array to create new 
// array contains student ‘name and grade in a string 
// [‘Ahmed 85’, ‘Elina 92’,… etc] 

let grades=[85,92,78,90,87,61,73];

let combineTwoArrays1=(arr1,arr2)=>arr1.map((item,index)=>item+" "+arr2[index]);
console.log(combineTwoArrays1(students,grades));

//Task7
//16.Combine it again to looks like this [[‘Ahmed’,85],[‘Elina’,92]] 
let combineTwoArraysNested=(arr1,arr2)=>arr1.map((item,index)=>[item,arr2[index]]);
console.log(combineTwoArraysNested(students,grades));


