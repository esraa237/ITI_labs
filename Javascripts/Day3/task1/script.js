//Task1
//1.Create an array called grades and initialize it with the grades of 
// seven students (e.g., [85, 92, 78, 90, 87,61,73]).
let grades=[85,92,78,90,87,61,73,9];

//Task2
//2.Calculate and print the average grade of the students in 
// the grades array (Note:  reduce). 
let calculateAverage=(grades)=>{
    let average=0;
    for(let index in grades){
        average +=grades[index];
    }
    average/=grades.length;
    return parseInt(average);
}
console.log(`Average: ${calculateAverage(grades)}`);
//with reduce 
//accumulator: The value resulting from the previous call ,initial with initialValue or if there isnt initial value arr[0]
//currentValue: The value resulting from the previous call,initial with arr[0] if there is initialValue otherwise arr[1] 
let average=grades.reduce((accumulator, currentValue)=>accumulator+currentValue)/grades.length;
console.log(`Average: ${parseInt(average)}`);

//Task3
//3. Find and print the highest grade in the grades array. 
let getMax=(grades)=>{
    let max=grades[0];
    for(let grade of grades){
        if(max<grade){
            max=grade;
        }
    }
    return max;
}
console.log(`Max: ${getMax(grades)}`);

let max=grades.reduce(function(accumulator,currentValue){
    if(accumulator>=currentValue)return accumulator;
    else return currentValue;
},-Infinity);
console.log(`Max: ${max}`);

//Task4
// 4. Find and print the lowest grade in the grades array.
let getMin=(grades)=>{
    let min=grades[0];
    for(let grade of grades){
        if(min>grade){
            min=grade;
        }
    }
    return min;
}
console.log(`Min: ${getMin(grades)}`);

let min=grades.reduce(function(accumulator,currentValue){
    if(accumulator>=currentValue) return currentValue;
    else return accumulator;
},Infinity);
console.log(`Min: ${min}`);

// Task5
// 5. Replace grade 90 to be 91

// let printArray=(arr)=>{
//     for(let item of arr){
//         console.log(item);
//     }
// }
let replace=(arr,oldItem,newItem)=>{
    let newArray=arr;
    let oldIndex=arr.indexOf(oldItem);
    newArray.splice(oldIndex,1,newItem);
    return newArray;
}
console.log("Array before replacement");
console.log(grades);
let gradesWithReplace=replace(grades,90,94);
console.log("Array after replacement");
console.log(gradesWithReplace);

//Task6
// 6. Sort the grades array in ascending order and print the sorted array.
//default sort function don't compare numbers
grades.sort();
console.log("Array after default sort");
console.log(grades);
grades.sort((a,b)=>a-b);
console.log("Array after modified sort");
console.log(grades);

//Task7
//7. Find students grades greater than or equal 60. name the new array successeStudents. 
//filter method don't change in the same array
let findGrades=(grades)=>{
    let result=grades.filter((grade)=>grade>=60);;
    return result;
}
console.log(findGrades(grades));

//Task8
//8. Convert grades to percentage array [‘85%’,’92%’,…..etc]. 
let convertToPercentage=(arr)=>{
    let result=[];
    for(let index in arr){
        result[index]=arr[index]+"%";
    }
    return result;
}
console.log("Convert grades to percentage array")
console.log(convertToPercentage(grades));
// map
let convertToPercentage1=grades.map((grade)=>grade+"%");
console.log(convertToPercentage1);

// Task9
// 9. Convert the grades array to a separated by comma. Print the 
// resulting string.

let gradesString=grades.toString(); //join()
console.log(gradesString);

