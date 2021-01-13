//libvoid.user.js v0.03b
/* to add into userscript
// @require https://raw.githubusercontent.com/FrozenVoid/libvoid.user.js/main/libvoid.js?number
where any 'number' change will re-download the script
*/
(function(){
function set_shortptof(short,long){
if(Document.prototype[long]){
  Document.prototype[short]=Document.prototype[long];
 remenum(Document,short);  
}
 
if(Element.prototype[long]){
 Element.prototype[short]=Element.prototype[long];
 remenum(Element,short);  

}
if(Node.prototype[long]){Node.prototype[short]=Node.prototype[long];
 remenum(Node,short);                     
 }
}
function remenum(base,proto_str){Object.defineProperty(base.prototype, proto_str, {enumerable: false});  }
var aliastable={'id':'getElementById','qsa':'querySelectorAll','qs':'querySelector',
'tag':'getElementsByTagName','cn':'getElementsByClassName','ce':'createElement',
'ga':'getAttribute','sa':'setAttribute','ap':'appendChild','ib':'insertBefore'}
for(var i in aliastable){set_shortptof(i,aliastable[i]);}
var globals={'dbg':console.warn}
for(var i in globals){Window.prototype[i]=globals[i];
   remenum(Window,i);                   

    }

 //node.parent()=Node.parent(1)=Node.parentNode;
Node.prototype.parent=function(x){
if(!x)return this.parentNode;
var p=this;
for(var i=0;i<x;i++)p=p.parentNode;return p}


//Node.child(1,2,4) -> Node.childNodes(1).childNodes(2).childNodes(4);
Node.prototype.child=function(){var p=this;
for(var i=0;i<arguments.length;i++)p=p.childNodes[arguments[i]]; return p}

Object.prototype.clone=function (){return Object.assign({}, this);};

Array.prototype.uniques=function(){return [...new Set(this)];}
Array.prototype.copy=function(){return this.slice(0);}
 
Array.prototype.median=function(){
var c=this.copy();c.sort((a,b)=>a>b);
return c[0|(c.length/2)]}

Array.prototype.sum=function(){var s=0;
for(var i=0;i<this.length;i++)s+=this[i]; return s;}

Array.prototype.average=function(){var s=a[0];
for(var i=1;i<this.length;i++)s+=this[i]; return s/this.length;}

Array.prototype.min=function(){var s=a[0];
for(var i=1;i<this.length;i++){if(s>this[i])s=this[i];} return s;}

Array.prototype.max=function(){var s=a[0];
for(var i=1;i<this.length;i++){if(s<this[i])s=this[i];} return s;}

if(! Array.prototype.equals){
 Array.prototype.equals = function (array) {
  if (!array || this.length != array.length)return false;
  var i=0,len=this.length;
  for(; i < len && this[i]==array[i]; i++){;}
  return i==this.length;
}}

 function logbias(M){const base=1.0001;
 //return random number with bias to lowest(use M-logbias() for inverse).
var mrange=Math.log(M)/Math.log(base);//logbase(M)=log b/log a
return Math.pow(base,(Math.random()*mrange));}
 //combined probability of argument probabilities
function prob(){var res=arguments[0];
for (var i = 1; i < arguments.length; i++){res*=arguments[i]}return res;}

var rand01=()=>(Math.random()>0.5)?1:0; 

var objproto=['clone']
var nodeproto=['parent','child']
var arrayproto=['min','max','average','median','copy','sum','equals','uniques']
for(var i in nodeproto){remenum(Node,nodeproto[i]);}
for(var i in arrayproto){remenum(Array,arrayproto[i]);        }              
for(var i in objproto){remenum(Object,objproto[i]);        }       
})()
