  function Dictionary(words) 
  {
    this.words = words;
  }
  
  Dictionary.prototype.findMostSimilar = function
  (str1)
  { 
     var fckLevArray = this.words.map((str2)=>fckLev(str1,str2));
     var min = fckLevArray[0];
     var final;
     fckLevArray.forEach((movs,ind)=>{
           if(movs<min)
           {
             min=movs
             final = this.words[ind];
           }
       }); 
       return final;
  }

  function fckLev(str1, str2) 
  {
  var t = [], u, i, j, size1 = str1.length, size2 = str2.length;
  if (!size1) { return size2; }
  if (!size2) { return size1; }
  for (j = 0; j <= size2; j++) { t[j] = j; }
  for (i = 1; i <= size1; i++) 
  {
    for (u = [i], j = 1; j <= size2; j++) 
    {
      u[j] = str1[i - 1] === str2[j - 1] ? t[j - 1] : Math.min(t[j - 1], t[j], u[j - 1]) + 1;
    } t = u;
  } return u[size2];
}
    
  
  
var d = new Dictionary(["cocoa","stronda","lasud","cacau","cocau","cocos","strwablerry"]);
var str = d.findMostSimilar("straberry");

console.log('most similar !! -> ' + str);