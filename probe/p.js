// see excelent article on https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Function
/*function makefunction(code){
return new Function('"use strict";return '+code)();
}
var add=makefunction(""+function(a,b){return a+b});
*/
//console.log("add : ",add(4,5));
"use strict";
require("crypto");
var module=require('./myModule.js');

console.log("mod: ", module(5,5));// those 5 and 5 can be values from other modules
var m="mama";
function execute(func){
	console.log("mama: ",m);
	//return 
	func(require("crypto"));
}
/*
function funci(s){
require("crypto");
console.log("mama2: ",m);
console.log("ps: ",s);
}
*/
execute((s)=>{
require("crypto");
console.log("mama3: ",m);
console.log("ss",s);
});