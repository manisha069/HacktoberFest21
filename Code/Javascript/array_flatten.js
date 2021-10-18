// array flat method is very useful for nested array to obtain them in a single array
// array flat

let arr = [1, 2, 3, [4, 5, 6, [7, 8, [9]]], 10, [11], [12, [13]]]
console.log(arr.flat(3)) // flat method

// array flat prototype
if (!Array.flat1) {
  Array.prototype.flat1 = function (depth = 1) {
    let flatArray = []
    flat(this, depth)
    function flat(inputArr, depth) {
      for (let i = 0; i < inputArr.length; i++) {
        if (typeof inputArr[i] == 'object' && depth > 0) {
          flat(inputArr[i], depth - 1)
        } else {
          flatArray.push(inputArr[i])
        }
      }
    }
    return flatArray
  }
}
arr = arr.flat1(3)
console.log(arr) // will provide deep level elements till 3 array
