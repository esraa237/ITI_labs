//Task1
// 1- Create function to register students data through prompts 
// (firstName, lastName, age, email, and department) 
// Bonus: validate email using regular expressions 
// function should retunes student data as an object 
let firstName,lastName, age, email,department;
let emailRegex;
let getStudentData=(index)=>{
    firstName=prompt(`Enter the first name of student${index+1}: `);
    lastName=prompt(`Enter the last name of student${index+1}: `);
    do{age=prompt(`Enter the age of student${index+1}: `);}
    while(isNaN(age));
    do{
        email=prompt(`Enter the email of student${index+1}: `);
        emailRegex=/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
    }while(!(emailRegex.test(email)));
    department=prompt(`Enter the department name of student${index+1}: `);
}
let registerStudent=(studentIndex)=>{
    getStudentData(studentIndex);
    let studentData={
        firstName,
        lastName,
        age,
        email,
        department,
        toString(){
            return `${this.firstName} ${this.lastName}`;
        }
    };
    return studentData;
}
//console.log(registerStudent(0));

//Task2
// 2- create array of students, then start push students coming from previous function into 
// this array. 
let allStudentsData=[];
let studentsNumber=prompt("Enter the number of students: ");
for(let index=0;index<studentsNumber;index++){
    allStudentsData.push(registerStudent(index));
}
console.log(allStudentsData);

//Task3
// find the oldest student fullName. 

let getOldestStudentFullName=(studentsData)=>{
    let oldestStudent=studentsData.reduce((accumulator,currentValue)=>{
        if(accumulator.age>=currentValue.age)return accumulator;
        else return currentValue;
    },-Infinity);
    return `FullName of the oldest student:${oldestStudent.firstName} ${oldestStudent.lastName}`;
}
console.log(getOldestStudentFullName(allStudentsData));

//Task4
//4- Now use your PascalCase Function in previous lab to convert last names and firstNames 
// in objects to PascalCase.
const toPascal=(input)=>{
    let convertedInput=input
    .toLowerCase()
    .trim()
    .split(" ")
    .map((word)=>word[0].toUpperCase()+word.slice(1))
    .join("");
    return convertedInput;
}
let convertStudentsDataToPascal=(studentsData)=> studentsData.map((item)=>{
        item.firstName=toPascal(item.firstName);
        item.lastName=toPascal(item.lastName);
        return item;
    })

console.log(convertStudentsDataToPascal(allStudentsData));

//another way
//we made spread item here because we made return direct 
let convertedStudentData = allStudentsData.map(item=>{
    return {
        ...item,
        firstName: toPascal(item.firstName),
        lastName: toPascal(item.lastName),
    }
});
console.log(convertedStudentData);

//Task5
//5- Find all students with ages greater than 20 

const filterStudentsWithAge=(studentsData)=>studentsData.filter((student)=>student.age>20);
console.log(filterStudentsWithAge(allStudentsData));

//Task6
// 6- Get the average age for all students 

const getAverageStudentsAge=(studentsData)=>{
    let studentsAverageAge=studentsData.reduce((accumulator,currentValue)=>{
        accumulator.age=Number(accumulator.age)+Number(currentValue.age);
        return accumulator;
    });
    return Number(studentsAverageAge.age/studentsData.length);
}
console.log(getAverageStudentsAge(allStudentsData));

//Task7
//7.Sort students ascending by firstName ,(if you have a match in firstName) then sort 
//descending by lastName

console.log("Sorting");
allStudentsData.sort((a,b)=>{
    if(a.firstName.toLowerCase()>b.firstName.toLowerCase()) return 1;
    else if(a.firstName.toLowerCase()<b.firstName.toLowerCase()) return -1;
    else{
        if(a.lastName.toLowerCase()>b.lastName.toLowerCase()) return 1;
        else if(a.lastName.toLowerCase()<b.lastName.toLowerCase()) return -1;
        else return 0;
    }
})
console.log(allStudentsData);

//Task8
//8- Generate a new array contains objects with two properties fullName and age 
let newStudentData=allStudentsData.map((item)=>{
    return{
    fullName:{
        firstName:item.firstName,
        lastName:item.lastName
    },
    age:item.age
}
})
console.log(newStudentData);

//Task9
//9- try students[0]+””  ? 
//before toString the output was: object Object
console.log(allStudentsData[0]+" ");

//Task10
//10- override toString method to solve the problem by print student fullname 
console.log(allStudentsData[0].toString());
console.log(allStudentsData[0]+" ");
//Task11
//11- Convert your array to JSON 
console.log(JSON.stringify(allStudentsData));