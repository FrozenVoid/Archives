// ==UserScript==
// @name        RedditContentFilter
// @namespace   reddit
// @description Filter reddit by Sub, Domain, User,Commentword,Titleword
// @include     https://*.reddit.com/r/*
// @include     http://*.reddit.com/r/*
// @include     https://*.reddit.com
// @exclude     https://*.reddit.com/*/search?*
// @exclude     https://*.reddit.com/*/comments/*
// @exclude     https://*.reddit.com/*/duplicates/*
// @exclude     https://old.reddit.com/*
// @version     1.21.1e
// @author  FrozenVoid
// @run-at document-end
// @grant       unsafeWindow
// @grant       GM_addStyle
// ==/UserScript==
unsafeWindow.norefresh=0
unsafeWindow.permablockrefresh=1;
unsafeWindow.only_visible_sub=1;//only allow visible subs.
var nextskip=50;//skip to next page if completed hiding
var domainblock=0//1
var userblock=0//1
if (typeof GM_addStyle == 'undefined') {
  this.GM_addStyle = (aCss) => {
    'use strict';
    let head = document.getElementsByTagName('head')[0];
    if (head) {
      let style = document.createElement('style');
      style.setAttribute('type', 'text/css');
      style.textContent = aCss;
      head.appendChild(style);
      return style;
    }
    return null;
  };
}

function refresh_page(){location.reload()}
//workaround 
function setdef(x){if(undefined===x)x="";}
setdef(window.localStorage.sublist);
setdef(window.localStorage.titlelist);
setdef(window.localStorage.domainlist);
setdef(window.localStorage.wordlist);
setdef(window.localStorage.userlist);

setdef(window.localStorage.permatitle1);
setdef(window.localStorage.permatitle2)
setdef(window.localStorage.permatitle3);
setdef(window.localStorage.permatitle4);
setdef(window.localStorage.permatitle5);

setdef(window.localStorage.permablock);
setdef(window.localStorage.permablock2)
setdef(window.localStorage.permablock3);
setdef(window.localStorage.permablock4);
setdef(window.localStorage.permablock5);

GM_addStyle(`


.unb1contains{border:2px solid gold;margin-top:2em}

`)
//change promoted link to comments
var commentslink=document.querySelector('ul.tabmenu>li>a[href$="/ads/"]')
if(commentslink){commentslink.href=commentslink.href.replace('/ads/','/comments/');commentslink.textContent="Comments";}

var debugon=1;
//enable debug for only this account.(replace  with 'debugon=1' for all )
function debugt(text){if(debugon)document.title=(text);}
function debug(text){if(debugon)prompt(text);}
function debuglog(text){if(debugon)console.log(text);}
var totalrefreshes=0;
unsafeWindow.forcecssreload=3000;
unsafeWindow.debuglastaction='Start loading'
setInterval(ref,250);
setInterval(blockedsubslisting,250);
attacheditor();

var ptitle1=window.localStorage.permatitle1||"X1";
var ptitle2=window.localStorage.permatitle2||"X2";
var ptitle3=window.localStorage.permatitle3||"X3";
var ptitle4=window.localStorage.permatitle4||"X4";
var ptitle5=window.localStorage.permatitle5||"X5";

//hide these subreddits completely(no unblock)
var permablock=getls("permablock","permablock1,psub1sub2")
var permablock2=getls("permablock2","permablock1,psub1sub2")
var permablock3=getls("permablock3","permablock1,psub1sub2")
var permablock4=getls("permablock4","permablock1,psub1sub2")
var permablock5=getls("permablock5","permablock1,psub1sub2")
var insubreddit=!!(document.querySelector('span.subscribers'));
var insidesearch=!!document.querySelector('div.searchpane.raisedbox');
//optimize out the other regex depending on whether page has comments.
var insidestory=!!(document.querySelector('div.md>textarea'));
if(insidestory){
var words=getls("wordlist","filtered1word|filtered2word",1);
if(words.replace(/\s/gmi,"").length<2)words="filtered1word|filtered2word";
var wordregex=new RegExp(words,"gmi");
}else{

var titles=getls("titlelist","filtered1word|filtered2word",1);
if(titles.replace(/\s/gmi,"").length<2)titles="filtered1word|filtered2word";
var titleregex=new RegExp(titles,"gmi");}

function forcerefresh(){
unsafeWindow.forcecssreload++;

;}

document.body.addEventListener('DOMSubtreeModified', forcerefresh, true);

function isblocked(v,listing){if(!v||!listing)return 0;
return listing.search(","+v)!=-1;}

function button3(text,oncl){var editall=unsafeWindow.document.createElement("button");
editall.innerHTML=text;
editall.setAttribute('class','ublocker');
editall.setAttribute("onclick",oncl);
return editall;}

function permbl(p){

return `<button title="Permanently remove from this listing  to permablock category:${ptitle1}" class ="sub1permblock" onclick="window.localStorage.permablock+=',${p}';setTimeout(function(){window.forcecssreload=3000;window.debuglastaction='permbl';window.permablockrefresh=1;},100)">${ptitle1}</button>` ;}
function permbl2(p){
return `<button title="Permanently remove from this listing to permablock category:${ptitle2}" class ="sub1permblock" onclick="window.localStorage.permablock2+=',${p}';setTimeout(function(){window.forcecssreload=3000;window.debuglastaction='permbl2';window.permablockrefresh=1;},100)">${ptitle2}</button>` ;}
function permbl3(p){
return `<button title="Permanently remove from this listing to permablock category:${ptitle3}" class ="sub1permblock" onclick="window.localStorage.permablock3+=',${p}';setTimeout(function(){window.forcecssreload=3000;window.debuglastaction='permbl3';window.permablockrefresh=1;},100)">${ptitle3}</button>` ;}

function permbl4(p){
return `<button title="Permanently remove from this listing to permablock category:${ptitle4}" class ="sub1permblock" onclick="window.localStorage.permablock4+=',${p}';setTimeout(function(){window.forcecssreload=3000;window.debuglastaction='permbl4';window.permablockrefresh=1;},100)">${ptitle4}</button>` ;}
function permbl5(p){
return `<button title="Permanently remove from this listing to permablock category:${ptitle5}" class ="sub1permblock" onclick="window.localStorage.permablock5+=',${p}';setTimeout(function(){window.forcecssreload=3000;window.debuglastaction='permbl5';window.permablockrefresh=1;},100)">${ptitle5}</button>` ;}
function unblock(p){
return `<button title="Unblock this subreddit from /r/all r/popular" class="unblockonesub" onclick="window.localStorage.sublist=window.localStorage.sublist.
replace(',${p}','');window.setTimeout(function(){ window.forcecssreload=3000;window.debuglastaction='unblock';window.permablockrefresh=1; },100);;">+unblock</button>` ;}

function getls(val,def,isregex){
if(window.localStorage[val])return (!isregex?",":"")+window.localStorage[val] ; return def}

function filteredword(storytitlearr){
if(!storytitlearr||!wordregex)return 0;
var storytitle=storytitlearr[0];
if(!storytitle)return 0;

return wordregex.test(storytitle.textContent)
//test if words in title match story title
//var regex=new RegExp(titlelist,'')
}

function filteredtitle(storytitlearr){
if(!storytitlearr||!titleregex)return 0;
var storytitle=storytitlearr[0];
if(!storytitle)return 0;

return titleregex.test(storytitle.textContent)
//test if words in title match story title
//var regex=new RegExp(titlelist,'')
}

//Refresh CSS states

function ref(){
if(unsafeWindow.norefresh){return;}
if(unsafeWindow.forcecssreload<10){return;}
unsafeWindow.forcecssreload=0;totalrefreshes++;
//debugt(totalrefreshes+unsafeWindow.debuglastaction);;
ptitleref();
if(insidestory&&unsafeWindow.wordregexchange){
wordregex=new RegExp(getls("wordlist","filtered1word|filtered2word",1),"gmi");unsafeWindow.wordregexchange=0;}
if((!insidestory)&&unsafeWindow.titleregexchange){
titleregex=new RegExp(getls("titlelist","filtered1word|filtered2word",1),"gmi");
unsafeWindow.titleregexchange=0;}
//window.moveTo(0, 0);
var stories=document.querySelectorAll('div[data-author]')
var subs=getls("sublist","dummysub.sub,dummysub2.sub2");
var domainlist=getls("domainlist","dummysub.sub,dummysub2.sub2");
var users=getls("userlist","dummysub.sub,dummysub2.sub2");

for(var i=0;i<stories.length;i++){
var showstory=1;
if(insubreddit){
if(insidestory){
//Story page:filter comments:word/author only
var wordmatch=!!filteredword(stories[i].getElementsByClassName('md'));
if(isblocked(stories[i].getAttribute('data-author'),users)||wordmatch)showstory=0;
}else{//Subreddit page:filter domain,user,title
var titlematch=!!filteredtitle(stories[i].getElementsByClassName('title'));//workaround 
if( isblocked(stories[i].getAttribute('data-domain'),domainlist) || isblocked(stories[i].getAttribute('data-author'),users) || titlematch)showstory=0;

}}else{//Subreddits global page:/r/all r/popular homepage
//filter by user,domain, subreddit, title,
var titlematch=!!filteredtitle(stories[i].getElementsByClassName('title'));//workaround 
if( (isblocked(stories[i].getAttribute('data-subreddit'),subs) )||isblocked(stories[i].getAttribute('data-domain'),domainlist)||isblocked(stories[i].getAttribute('data-author'),users)||titlematch)showstory=0;

}

//if(!showstory)debug(stories[i].textContent+"::"+wordregex.toString())

stories[i].style.display=((showstory)?"block":"none");
if(showstory){
stories[i].setAttribute('isvis',"set")
stories[i].setAttribute('ishidden',"")
}else{
stories[i].setAttribute('isvis',"")
stories[i].setAttribute('ishidden',"set")
}

}
unsafeWindow.permablockrefresh=1;

 blockedsubslisting();addblockers();}

//================Add block buttons to content nodes=====
function addblockers(){
var divs=document.querySelectorAll('div[data-author]:not([blocker=set])')
for(var i=0;i<divs.length;i++){
divs[i].setAttribute('blocker','set');
//domainless/subless posts are not stories.
var thedomain=divs[i].getAttribute('data-domain');
if(thedomain){
if(domainblock){
divs[i].getElementsByClassName('domain')[0].parentNode.appendChild(button3(" [BLOCK DOMAIN] ","window.localStorage.domainlist+=',"+thedomain+"';window.forcecssreload=3000;window.debuglastaction='BLOCK DOMAIN(block button)';"));}

var thesub=divs[i].getAttribute('data-subreddit');
if(thesub){
var addsub=button3(" [BLOCK SUBREDDIT] ","window.localStorage.sublist+=',"+thesub+"';window.forcecssreload=3000;window.debuglastaction='BLOCK SUBREDDIT(block button)';");
var attachsub=divs[i].getElementsByClassName('subreddit');

if(attachsub&&attachsub[0]!=null){attachsub[0].parentNode.appendChild(addsub);};;
;}

}

var theuser=divs[i].getAttribute('data-author');
if(theuser&& userblock)divs[i].getElementsByClassName('author')[0].parentNode.appendChild(button3(" [BLOCK USER] ","window.localStorage.userlist+=',"+theuser+"';window.forcecssreload=3000;window.debuglastaction='BLOCK USER(block button)';"));
}}

//UTility func
function button(text){var editall=unsafeWindow.document.createElement("button");
editall.innerHTML=text;
return editall;}

function addbuttons(){

var atpoint0=unsafeWindow.document.querySelector('p.users-online');

  var atpoint1=atpoint0?atpoint0:unsafeWindow.document.querySelector('#search').parentNode;

var testat=document.getElementById('EditallButtons')
var atpoint=testat?testat:document.createElement('div')
atpoint.id="EditallButtons";
for(var i in arguments)atpoint.appendChild(arguments[i]);
atpoint1.appendChild(atpoint);
}

//Attach Edit blocklists and Unblock buttons

function ptitleref(){
 ptitle1=window.localStorage.permatitle1||"X1";
 ptitle2=window.localStorage.permatitle2||"X2";
 ptitle3=window.localStorage.permatitle3||"X3";
 ptitle4=window.localStorage.permatitle4||"X4";
 ptitle5=window.localStorage.permatitle5||"X5";

}
function attacheditor(){
ptitleref()

var editall=button(" [Edit SUBREDDIT blocklist  (total:"+window.localStorage.sublist.split(',').length+")] ")
editall.setAttribute("onclick","var r=prompt('Edit the subreddit block list:comma-separated words: subreddits can also be unblocked by buttons on the blocked subs listing below on this page',window.localStorage.sublist);if(r){window.localStorage.sublist=r;window.forcecssreload=3000;window.debuglastaction='EDIT DSUBREDDIT list';}")

var editall1p=button(" [Edit subreddit permablock category:  ("+ptitle1+") (total:"+window.localStorage.permablock.split(',').length+")] ")
editall1p.setAttribute("onclick","var r=prompt('Edit the SUBREDDIT unblock ([+]Subname)buttons permablock1::comma-separated words: These (already) blocked subreddits will not show up on the page below as unblock [+]Subname button',window.localStorage.permablock);if(r){window.localStorage.permablock=r;setTimeout(function(){window.forcecssreload=3000;window.permablockrefresh=1;window.debuglastaction='EDIT  prmablock1 list';},300);}")

var editall2p=button(" [Edit subreddit permablock category:  ("+ptitle2+") (total:"+window.localStorage.permablock2.split(',').length+")] ")
editall2p.setAttribute("onclick","var r=prompt('Edit the SUBREDDIT unblock ([+]Subname)buttons permablock2::comma-separated words: These (already) blocked subreddits will not show up on the page below as unblock [+]Subname button',window.localStorage.permablock2);if(r){window.localStorage.permablock2=r;setTimeout(function(){window.forcecssreload=3000;window.permablockrefresh=1;window.debuglastaction='EDIT D permablock2 list';},300);}")

var editall3p=button(" [Edit subreddit  permablock category:("+ptitle3+") (total:"+window.localStorage.permablock3.split(',').length+")] ")
editall3p.setAttribute("onclick","var r=prompt('Edit the SUBREDDIT unblock ([+]Subname)buttons permablock3::comma-separated words: These (already) blocked subreddits will not show up on the page below as unblock [+]Subname button',window.localStorage.permablock3);if(r){window.localStorage.permablock3=r;setTimeout(function(){window.forcecssreload=3000;window.permablockrefresh=1;window.debuglastaction='EDIT permablock3 list';},300);}")

var editall4p=button(" [Edit subreddit  permablock category: ("+ptitle4+") (total:"+window.localStorage.permablock4.split(',').length+")] ")
editall4p.setAttribute("onclick","var r=prompt('Edit the SUBREDDIT unblock ([+]Subname)buttons permablock4::comma-separated words: These (already) blocked subreddits will not show up on the page below as unblock [+]Subname button',window.localStorage.permablock4);if(r){window.localStorage.permablock4=r;setTimeout(function(){window.forcecssreload=3000;window.permablockrefresh=1;window.debuglastaction='EDIT permablock4 list';},300);}")

var editall5p=button(" [Edit subreddit  permablock category: ("+ptitle5+") (total:"+window.localStorage.permablock5.split(',').length+")] ")
editall5p.setAttribute("onclick","var r=prompt('Edit the SUBREDDIT unblock ([+]Subname)buttons permablock5::comma-separated words: These (already) blocked subreddits will not show up on the page below as unblock [+]Subname button',window.localStorage.permablock5);if(r){window.localStorage.permablock5=r;setTimeout(function(){window.forcecssreload=3000;window.permablockrefresh=1;window.debuglastaction='EDIT permablock5 list';},300);}")

var editall2=button(" [Edit DOMAIN blocklist (total:"+window.localStorage.domainlist.split(',').length+")] ")
editall2.setAttribute("onclick","var r=prompt('Edit the DOMAIN block list:comma-separated words',window.localStorage.domainlist);if(r){window.localStorage.domainlist=r;window.forcecssreload=3000;window.debuglastaction='EDIT DOMAIN list';;}");

var editall3=button(" [Edit USER blocklist (total:"+window.localStorage.userlist.split(',').length+")] ")
editall3.setAttribute("onclick","var r=prompt('Edit the USER block list:comma-separated words',window.localStorage.userlist);if(r){window.localStorage.userlist=r;window.forcecssreload=3000;window.debuglastaction='EDIT USER list';;}");
var ed4str=`var r=prompt('Edit the TITLE wordfilter regex::::Enter regex words enclosed by ∖b (word boundary=backslash b) and separated by | (regex OR) ex:  ∖bword1∖b|∖bword2∖b  ::::',window.localStorage.titlelist);if(r){window.localStorage.titlelist=r;window.forcecssreload=3000;window.debuglastaction='EDIT  TITLE list'; window.titleregexchange=1;}`;

var editall4=button("[Edit TITLE wordfilter (wordsets:"+window.localStorage.titlelist.split('|').length+")]")
editall4.setAttribute("onclick",ed4str)
var ed5str=`var r=prompt('Edit the COMMENT wordfilter regex:::::Enter regex words enclosed by ∖b (word boundary=backslash b) and separated by | (regex OR) ex:  ∖bword1∖b|∖bword2∖b  ::::',window.localStorage.wordlist);if(r){window.localStorage.wordlist=r;window.forcecssreload=3000;window.debuglastaction='EDIT COMMENT list'; window.wordregexchange=1;}`

var editall5=button("[Edit COMMENT wordfilter (wordsets:"+window.localStorage.wordlist.split('|').length+")]")
editall5.setAttribute("onclick",ed5str)
var blockall1=button("Block all visible subs(total:"+(document.querySelectorAll('div[data-subreddit]:not([ishidden=set])')).length+")")
blockall1.setAttribute("onclick",`var cursubs=document.querySelectorAll('div[data-subreddit]:not([ishidden=set])');for(var i=0;i<cursubs.length;i++){window.localStorage.sublist+=','+cursubs[i].getAttribute('data-subreddit');};window.forcecssreload=3000;window.debuglastaction='Block all visible subs';;`);;

var allstext=document.createElement('div')

allstext.setAttribute("style","width:100%")
allstext.setAttribute("id","bsubs_listing1");
var allstext2=document.createElement('div')

allstext2.setAttribute("style","width:100%")
allstext2.setAttribute("id","bsubs_listing_cats");
if(insidestory){
addbuttons(editall3,editall5,allstext);
}else if(insubreddit){
addbuttons(editall2,editall3,editall4,allstext);

}else if(insidesearch){
addbuttons(editall,editall2,editall3,editall4,editall5,blockall1,editall1p,editall2p,editall3p,editall4p,editall5p,allstext2,allstext);
blockedsubslisting();
}else{
addbuttons(editall,editall2,editall3,editall4,editall5,blockall1,editall1p,editall2p,editall3p,editall4p,editall5p,allstext2,allstext);
blockedsubslisting();
}

} 

function blockedsubslisting(){
if(!unsafeWindow.permablockrefresh)return;
var divs=document.querySelectorAll('#siteTable>div[data-subreddit]')
if(unsafeWindow.permablockrefresh){
permablock=getls("permablock","permablock1,psub1sub2");
permablock2=getls("permablock2","permablock1,psub1sub2");
permablock3=getls("permablock3","permablock1,psub1sub2");
permablock4=getls("permablock4","permablock1,psub1sub2");
permablock5=getls("permablock5","permablock1,psub1sub2");
ptitleref();
unsafeWindow.permablockrefresh=0;}

var pstr="";
var duplicate=[];
var subs_blocked=getls("sublist","dummysub.sub,dummysub2.sub2")

for(var i=0;i<divs.length;i++){

if(!isblocked(divs[i].getAttribute('data-subreddit'),subs_blocked)){continue;}
duplicate.push(divs[i].getAttribute('data-subreddit'));}

duplicate=duplicate.sort();
var counts=[];
for(var i=0;i<duplicate.length;i++){
if(counts[duplicate[i]]){counts[duplicate[i]]++}else{
counts[duplicate[i]]=1;}
}

var initheading=0;
for(var i in counts){
var pname=i;
if(permablock.search(","+pname)!=-1)continue;
if(permablock2.search(","+pname)!=-1)continue;
if(permablock3.search(","+pname)!=-1)continue;
if(permablock4.search(","+pname)!=-1)continue;
if(permablock5.search(","+pname)!=-1)continue;
if(initheading==0){
var headstr=document.getElementById('bsubs_listing_cats')
headstr.innerHTML="<br><h1>SUBREDDIT list<br> [+]==Unblock"+(insubreddit?" From r/all":"")+"<br>[Xn]== add to (permablockN) and don't display:<br> Click CategoryName to add to one of permablock categories(rename them below): </h1>";

headstr.appendChild(button3("Rename "+ptitle1,"window.localStorage.permatitle1=prompt('enter New Category name',window.localStorage.permatitle1);setTimeout(function(){window.forcecssreload=3000;window.permablockrefresh=1;window.debuglastaction='Rename permacat1';},100)"))

// setTimeout(function(){window.forcecssreload=3000;window.permablockrefresh=1;},300)
headstr.appendChild(button3("Rename "+ptitle2,`window.localStorage.permatitle2=prompt('enter New Category name',window.localStorage.permatitle2);setTimeout(function(){window.forcecssreload=3000;window.permablockrefresh=1;window.debuglastaction='Rename permacat2'},300)`))

headstr.appendChild(button3("Rename "+ptitle3,`window.localStorage.permatitle3=prompt('enter New Category name',window.localStorage.permatitle3);setTimeout(function(){window.forcecssreload=3000;window.permablockrefresh=1;window.debuglastaction='Rename permacat3'},300)`))

headstr.appendChild(button3("Rename "+ptitle4,`window.localStorage.permatitle4=prompt('enter New Category name',window.localStorage.permatitle4);setTimeout(function(){window.forcecssreload=3000;window.permablockrefresh=1;window.debuglastaction='Rename permacat4'},300)`))

headstr.appendChild(button3("Rename "+ptitle5,`window.localStorage.permatitle5=prompt('enter New Category name',window.localStorage.permatitle5);setTimeout(function(){window.forcecssreload=3000;window.permablockrefresh=1;window.debuglastaction='Rename permacat5'},300)`))

//+[ptitle2,ptitle3,ptitle4,ptitle5]
initheading=1;}

pstr+="<div  class='unb1contains'>"+(counts[i]>1?"Counts:":"Count:")+counts[i]+"<br>"+unblock(pname)+"<a class='unb1linksub' href='/r/"+pname+"'>"+pname+"</a>"+permbl(pname)+permbl2(pname)+permbl3(pname)+permbl4(pname)+permbl5(pname)+"</div>";

}

var attp1=document.getElementById('bsubs_listing1');
if(attp1){attp1.innerHTML=pstr;}
}
//Hide all stories button

var b=document.createElement('button');
var b2=document.createElement('button');
var oncstr2=`
function eventFire(el, etype){
  if (el.fireEvent) {
    el.fireEvent('on' + etype);
  } else {
    var evObj = document.createEvent('Events');
    evObj.initEvent(etype, true, false);
    el.dispatchEvent(evObj);
  }
}

function upall(){window.norefresh=1;
var a=document.querySelector('div[isvis="set"] form.hide-button>span>a');
if(!a){

document.getElementById("HideAllButton").innerHTML="Completed hiding:Next page->";
document.getElementById("HideAllButton2").innerHTML="Completed hiding:Next page->";

var next=document.querySelector("span.next-button>a");
if(next&&${nextskip}){  next.click();}

return;
}else{
eventFire(a,'click')}

window.setTimeout(upall,500+(0|(Math.random()*3000)));
var leng1=document.querySelectorAll('div[isvis="set"] form.hide-button>span>a').length;
document.getElementById("HideAllButton").innerHTML="Remaining: "+leng1 +" stories"
document.getElementById("HideAllButton2").innerHTML="Remaining: "+leng1+" stories"

}

upall()

`

function finalbuttons(){
  var totalstories=document.querySelectorAll('form.hide-button>span>a').length;

  var numstories=document.querySelectorAll('div[isvis=set] form.hide-button>span>a').length;
  if(!numstories && nextskip){//autoskip
 if(document.querySelector("span.next-button>a"))
   document.querySelector("span.next-button>a").click();

  }
var visstories="Hide All Stories("+numstories+"/"+totalstories+")";

b.setAttribute('onclick',oncstr2);
b2.setAttribute('onclick',oncstr2);
b.setAttribute('id',"HideAllButton")
b2.setAttribute('id',"HideAllButton2")
b.innerHTML=visstories
b2.innerHTML=visstories
unsafeWindow.document.querySelector("#header-bottom-left").appendChild(b2);
unsafeWindow.document.querySelector("#header-bottom-left").innerHTML+=`<a href="https://www.reddit.com/prefs">prefs</a>
<a href="https://www.reddit.com/message/inbox"> inbox</a>
<a href="https://www.reddit.com/u/me"> profile</a>
<a href="https://www.reddit.com/explore"> explore</a>
`

;unsafeWindow.document.querySelector('#siteTable').parentNode.appendChild(b);}

setTimeout(finalbuttons,1000)
