// Task 1.1:
// When the function called display 3 prompts on the page one by one to take 3 grades for  3
// students .
// Then display the grades on console after taking them
// Note:  use normal for loop
// Task 1.2:
// From 1.1. Instead of display the grade values , I want you to display grads summation
// Did you find any problem ??
// Note:  to solve any problem try to use parseInt or parseFloat  built-in javascript functions
// Task 1.3:
// From 1.2 .  Now instead of take 3 students from user, Ask the user first about how many
// students grads do we have by a prompt
// Then start take the grades and display their summation
// Task 1.4:
// From 1.3 .   Now we are ready to make some validations on how many students grades do we
// have?
// add a check after taking number of grades from user to make sure that the number between 2
// and 10
// display error message USING alert method instead of print the summation value, otherwise
// display the summation
// Task 1.5:
// From 1.4 .   we need to add more validations on the grades
// what if the user insert a grade like this 
// 3eman  ??
// we will have a problem with the summation result! (try it with previous task 1.4)
// So we need to make sure that user inserted a numeric value , if not the number will be
// considered as ZERO
// Note:   we will need isNaN()  javascript built-in method
// Task 1.6:
// From 1.5.   we need to be more advanced
// Instead of considering the wrong grade value as Zero we will show the prompt again asking for
// the correct grad until the user inserted correctly
// Task 1.7:
// From 1.6.   now add an extra validation on grades to be between 0 and 100 

// const getStudentGrade=function(){
//     let sum=0;
//     for(let i=0;i<3;i++){
//         let grade=prompt(`Enter the Grade of student ${i+1}:`);
//         console.log(grade);
//         sum+=parseInt(grade);
//     }
//     console.log(`Sum:${sum}`);
// }

const getStudentGrade = function (numberStudents) {
    for (let i = 0; i < numberStudents; i++) {
      let grade = prompt(`Enter the grade of student ${i + 1}:`);
      while (isNaN(grade)) {
        grade = Number(
          prompt(
            `Valid Number!! Enter the Correct Grade of student ${i + 1} As A Number:`
          )
        );
      }
      while (!(grade > 0 && grade < 100)) {
        grade = Number(
          prompt(`Valid Number!!  Enter the Grade of student ${i + 1} Between 0 and 100:`)
        );
      }
      console.log(grade);
      sum += grade;
    }
    console.log(`Sum:${sum}`);
};

let sum = 0;
let numberStudents;

do{
  let counter=0;
    if(counter!=0){
        window.alert("Valid Number!!  number should be between 2 and 10");
    }
    numberStudents = prompt("Enter the number of students between 2 and 10: ");
    if(numberStudents==null){
        break;
    }
    counter++;
}while (!(numberStudents < 10 && numberStudents > 2)||isNaN(numberStudents))
    if(numberStudents!=null){
getStudentGrade(numberStudents);
    }