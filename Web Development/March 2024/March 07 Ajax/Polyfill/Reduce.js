let arr = [1, 2, 3, 4, 5];
// let x = arr.reduce((acc, val, indx, arr) => {
//     return acc * val;
// })
// console.log(x);

Array.prototype.myReduce = function(fun, initVal){
    let arr = this;
    let acc, start_indx;
    
    if(typeof(initVal) != "undefined"){
        acc = initVal;
        start_indx = 0;
    }
    else{
        acc = arr[0];
        let start_indx = 1;
    }

    for(let i = start_indx; i < arr.length; i++){
        acc = fun(acc, arr[i], i, arr);
    }
    return acc;
}

let newArr = arr.myReduce((acc, val, indx, arr) => {
    return acc * val;
}, 0)
console.log(newArr);