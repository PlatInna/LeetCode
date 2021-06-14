#pragma once
/*
Given a list of unique words, return all the pairs of the distinct indices (i, j) in the given list, so that the concatenation of the two 
words words[i] + words[j] is a palindrome.
Example 1:
Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
*/
#include<string>
#include<vector>
#include<unordered_map>
#include "..\..\profile.h"


//TLM
vector<string> words = {
        "hf","ec","gdb","fabgjafbf","af","agecbbjjeeideih","ghfhhahgcibffhggh","fhichih","cibafefjagdffc","jghehbbiadh","dccagjhieg",
        "aibghiehhcchdafif","fgahfbiihe","adgdfhadcdjjfccaghg","fgjjfhehgaiiciiejdbc","abbicii","ce","hagfddhaej","bgcijbefe","bdg",
        "ajjjeafggbadecfahih","ijahchhcfbggefafbgf","iaadcgeifef","bifib","adbehigfebh","ddeaajihjbgfdd","dcfaaecdgbi","gcj","dfihgia",
        "dgcafeb","gfbiccffdifhhfhhi","fahjiiihhfciegjedhd","jiaihbgabigbdbdhdd","iifgebdejddabagjhcde","hhdgffjdfeafajdee","cjgajaheafeie",
        "fhdgejcbcbdcjiffgd","c","ibd","ieccgebahaffhegdgdd","dahf","ddjfhfeejecibj","bbaeicdaageecchje","ajcbfchhfbfefbfhdigj","hbcjfjdiicae",
        "daddfeaafhdah","bifdjadabicajfcejfb","gidjdcibehaicejjcf","eeahejajehcfigjcdf","dhgejaiheejjaadegfja","jibfccdcjg","dcafcddjcabccjhjgig",
        "igciaeiidfdhcgbaihbe","gfcbfiibjcj","fecdidih","aeidfgajf","abei","hidafgiddehebfdhhcdd","jcijc","fffcfbehgbjfeife","jbgcchhie",
        "jfejdihgggdjijjbeicj","cjifjecba","bebccecddbiicaibfi","cjjfhjacbbbc","abiddgdiicfhfddfbc","fjgedbhjeeaj","aeiadic","ab","igfhhjeajb",
        "ijdhgiifaedehch","ffibcidf","fgiajcbifgc","ceddacdjdacjdjjgei","ieai","bfejge","ejfhicdd","bbgjbajjdjheifeghjee","fifhhdcebbbjg",
        "ecbhdebc","hejffcfbfchahcdigh","ibffjacdhebe","cebjc","adfijhejc","ebjfeaffbcbhdcdgebch","eaced","fheafdbec","iabibeag","habhfbdddjeja",
        "fehbhbieggdgdhbicfj","efifjbacce","jgedceifggdbbfjiea","egbdcjeage","jajhifj","fiiafcbjd","gjhd","ecbcb","jcihjcbdc","h","jcf",
        "gdbdgihceeiifhida","aeihfhhhiheiigej","ifcbjedfhafgjg","cgif","fadfjdagbeiejhegf","faigdcfdihibighgf","ihfjjigahcfja","daeibjcahjdbeae",
        "chebcefiibbgd","cdbejafihg","ibfhjbejggajgdhebaeg","d","fbjhdfciceibfiabjfd","ggeid","hhehi","cjfbah","igbgjaiciddfif","hejgbi","cifibde",
        "aiecbigeddjfge","hbifcghbababhjib","gie","jjaaihhdcdba","dcfigdiaghiheegf","defdj","cddibiiicjefggdefi","ehfhh","bdhbgddgabghea",
        "jbjhachejcj","ccedf","efehbbjhgg","ifahaiciajfeegfa","ae","cdcfgfbceb","jdgbhcgdhgjfbaegcfd","ja","bebdi","fijdicf","hjbjdddffggjjdihdj",
        "adaih","idbijgeaaiadeeijgcaj","eadcejdi","cdghfgiijga","afiibdfjgdfde","ig","fbciifeh","cfdfggfgceaccddd","bgfifjdei","eddccajdbihbbejjeije",
        "addidedafiihb","ahagfcagbjah","cjjhhjjidhceiai","geb","jecciidjjfabaccecd","a","behii","accihhe","fjd","jbfa","giia","ag","cgfjhdgdfedcijghih",
        "bdabic","gjafha","aibihaafghjifhdeicdj","ejeibaegbddjeheiied","hcjgfdjfcgbbedeaea","gdcceceihgbej","fdf","idhfefebb","ecdijjhgdaaafg",
        "agecicdfibe","fggecagdbbgh","gbfajfeaac","hdgfgacdaf","ciifbjbhcafbhib","gdeebgfe","heicafbahdad","hggiebcihdj","hbieegcihddfeghfca",
        "jjcgchjf","hbjbcdghiaghcag","gdaiaibcjafgfciecib","fhfjacgficbdej","fgdfghabijjdbfi","f","cfbcihbejgcacj","cg","hecfdhdd",
        "hbddgfddiieffjjbcjcf","iifjcgji","daafbhjjdaagcibhjihi","gab","jaefjcgja","fedbbhddgdf","fidb","aahifcfbfcedgihehe","ajaifgiai",
        "fdcjdfdhgecdebjifjc","cehhbcag","acdefjjh","bihdfaafbfffhd","hhfehjgjb","febghhd","jidji","fab","ggcfdhae","bdbgiijabieij",
        "hddajcfbbfijhaigh","fedfjbe","ddbjbdai","jfjjbbefgbecjcbhjdce","ijefg","jeeagddbjjadeaeddhe","ghideebj","jheibcjgaecfhdceea","ee",
        "gcdfccegcedie","igbbfc","ifeedefcjbb","fbgdh","fbdg","adecjdicgcgheaiaddie","jgeaafgcfjchb","babcefcgjjfj","fhhdhecejecej","hagejedjeagaiij",
        "bbgh","i","aeedcebhhbhjhejcecje","jcei","bjibedbaaiabebddidfi","jgdibeaicfcficiie","gbeihefaeehgafajic","eah","efaica","fcfea","ebiabbed",
        "hjied","ahbabafaffeiebd","bjbfdbahecjffefhbeci","aef","hgjbffjhgcj","hfgeidfd","hdcjihbfhfahji","hhjabhagggjjebbicife","cdcdhfaagcg",
        "bcaaca","abheebfafbfighcjife","edhiebbgfijfgidb","ch","bgjfcdicfa","jcijecgeghigb","jeafbj","dbhgafgfeaefg","bcajgjgbb","adjaacefbjbhbhib",
        "bfjcdh","eecgccea","fca","bihghh","bjcafgcejhja","iagfeiebahjbhh","cdfgjabhhdhcji","jcgdadfba","afcgdefhhhfbg","chdicdaehdgidj",
        "bjifiijhjigede","afichgcejffhgjgfbef","dcagbcfijdifafhhdfhe","ib","jhab","dfgjbgideidajagad","hfj","dhgg","cdefjd","echeehdegjfhhgf",
        "gjcii","jb","edbfhj","gfehfiiicijcdjiadihf","ffhgdgdbhcdgheid","fidcdjibhgbj","bdhjebdghfjbggb","djfbgaejch","ejbhjhbhjahfeeh",
        "hgddddfdcjcb","eeiigfjcd","cgbabdeefebgacbgb","afafdhhijcafj","hdh","cejbjdifaedg","iaajifaffhhccieibdca","bbijccjfdcbg","gbbceaihabfcabi",
        "bdgjhijdgbcccdif","efehcicaeh","abdc","iadgibgga","ibbd","iicgbaehddi","ffdajgbag","chcbahdjbha","bfhdccfjcdejag","gbaecjchcjh","ei",
        "ieafiahcje","fgbfhgah","iieddjbhj","jeehjfcfgf","gggaajijieeagaee","edagbf","acha","eijccgg","iiehcbadgccc","cjghbffbjdahjfddgj",
        "bghbebjabicgchicca","iecdcjhajifbhgddjhf","dejabgeiaihjecbgaeea","gdefhacefidecdfjieg","aebbge","ciabbjhadibceajgjg","fceadfchgafgag",
        "ebbcgdcdei","jgahhgbhahcja","fhgjaaddij","fjdacaidaagh","eihdcdh","eibiachhacjjigieeb","haecjjhcigicbeadjd","ecgjciaiehaeacdga","geijahc",
        "cjhfaihjdhacfjacg","chjdibjgfece","bag","aeehg","chc","bagffgjhcgagjdi","hhefbjdegibacebcbbe","hbbjaddidjjdi","jcafdbhdh","cgjegied","ebegj",
        "ffhgagdhcggdhaja","cdgabebej","bcajheibhffdbg","gja","bidfdfgagacci","jdaebaieee","dbceachijhfdhahcaci","bcjaaiejgggehchjggab",
        "beaggcaijcigjfi","cacgagihjfhbaeiff","eiiheahddbicadfgce","iejd","bc","dfgdfgegdhcgbeb","cihj","acbcahhhcah","bdafhiddcaagadgfbf",
        "ecfjfcbdfigcacicec","dbficdeiicfcj","jiffh","ggda","bihhahdgdifb","ebbdgiefgcjccddb","ddfhaahbjgc","cjcdbjgjdcfh","hjgbj","jdicgbf",
        "jbffidccbjeb","dhdhb","cfecibedghhdgecififf","iihidabiiea","gchdigifg","adjjehahgdd","bfhcdhcciajegaicaa","hfcicjhdgbfgcghd","cebcdagjhhi",
        "fjbcabdef","fhafdecggfbgbcbbgbc","aa","gafahccgiaciba","ffjjajibidgfc","acdbfecdhagd","eegcdahb","eadeigaicgd","jhfjhajiigici","gej",
        "jjchgfafbfdhiah","jcjji","hjicjjeeej","hibbgdifhifh","chgicicdifc","aafjagiebgcffe","hhhbcgfhdifd","hcaachhaddjjc","hdfb",
        "cedcijifiajdfeejffcc","hadgaddcgfjjdejg","ciic","dd","beabcjcjghdjhiih","cajiahjjjbeadee","cifieedh","idaf","ahadgeej","ebehchcibi",
        "djgfdggbejfbjiefe","icf","gfeebgcbhehcggchh","djjccecee","abibjgaidbac","ebg","daijgeda","gfcfhbef","dchjbaf","afhci","adgbgjaiehdabjdhccf",
        "iadcagjfidejca","ebdj","fffdahhbgiibbihfjgc","ahcbadgefhfagd","hd","iibiajf","efifbhhibcac","eacifihidejbeiag","fg","cdffebjj",
        "icehdjddghachhfba","biigd","fecghdgfjjbici","fii","bhafjbjddeibg","bffie","djbfageghjgeadeie","cj","fcaehege","fib","gehaed","b",
        "iicgfffdfj","afahdb","bbedbjfgaeajaai","gfeeedh","fddffbijjdafdgj","hgibfjifhcdhg","caibiaaajh","fhigfcgbhga","cicb","dbfag",
        "bahfdigaejahhbejdbd","edeeahedjcgabcifia","hghciecdhh","aecdicgagbdbeeiacch","adbeicbgh","eagb","baceeaeafceejjidaje","ghdbfeadd",
        "eaedhabcaed","ihcag","jbgbjcjeeafgjheec","g","eddfjgeijfbeff","eaegjcdjggidjcjdaa","gcjabadahbefgjcejgd","gfcciihfjb","gfiijcibgjhbaidaga",
        "jihjfecfhiiaaeheghdg","bja","afjecfhce","dhfccadie","j","jgjhbjgjdccea","eehfdcidafei","gfcgbfeaagfga","djcaajabfbfadbacffbd",
        "ajcibibbdjdbdaffagad","cbdjiagf","acgehdejfajbgcgifhj","hjba","jehhicaigbdh","ajihajgfef","egfafhbcebeedghadh","caif","geeidffbh","jadceg",
        "deefjjhafghb","dfe","aajgadf","jdebahhedge","bdbgdiebjdggjfecfdi","eaigijfigebcfgagg","jfeafdeea","adbhhghjeedjcfejhe","ccfaaag",
        "ifcijbfiahihegighbj","fbfeeeibbbga","aeighbjaafagef","acdgjdbighdeee","cdfhcdahfbdcdchhhfi","bcdidgidjijdeifibjcb","hhcdibhdfa",
        "jebecgbafaehdiddc","bdfdajeaghhgdhj","ebii","hcgagchgh","cifaedibfb","cabbfijecbgdggddhbe","heabh","hdd","afc","cbcbjcbcih",
        "adebiadchcdfchdg","babhfifijhbahgdhdgea","adbicjhhcj","jaf","fbgea","jdi","hbdcejbcccjcid","dbdc","afhbechbgjhffgfcejh","aegcgfiigd",
        "chgifie","bdffhjcjchfegiid","cbfa","jee","gaaaifcjhhgdbbc","jhhc","ef","dbfdfiiiafdibhbecj","aicagb","fcb","bjahfccccajgj",
        "cdjdbghjiafbbbedegbh","jbgacdjfi","ahfgeaebcggc","iefje","deajed","bia","fb","cdeefbbfajhbfbdij","gdbjfcgajdabjafaf","hciaajjf",
        "hccbhcgihaciegdhig","eidhjacfdgh","fbcgaggeigihdi","jjecehghajj","difhdajbegbfegij","ghgigbaac","eiiififiechceajcj","jejghgiabcf","jajba",
        "ecdd","ggfiafjhddhjhiegbfj","igdgceegjegiajhihga","ajjafdheac","iehchdfaaajhjhbdfgg","fiea","dghad","deichgfgjheagjbgib","gf","eegdhdaaaih",
        "baecjgafadjbbbbe","aibeefbi","ejjdhaecbia","cfdjjhiheggehcefgbed","fafcab","bfjfgdeg","agiahejecbhafigfg","jhicieajhibffggfg","dfgejbag",
        "djgacicjbgbdd","hifabjhfj","ecgeehiiaffagfchch","ddgjhcdaeheghjdhj","dadjgijgiagjfiahgdjj","hgcdifdaghab","eaabdeahe","dhgdfbgbedcjdhijfhb",
        "hcj","fjchcjjgeifg","fachbidaebjbbe","idaiccj","ebbedabhibbi","egcecjdebhcjffb","haaedahgjfbdd","hahagjigc","fgghffd","djhcic","fgcdcechfe",
        "iiagciehefaejb","ahhc","hchejafjdeccfb","ca","jbjeiiehjg","fbibfcf","gdfdfefcgbahjd","idbjadeehfdfjjaggd","bjdhbdcecddgcgdi","jcgajbggg",
        "adhfjhibghjihhaef","ifb","gfe","ahgdcfdbededbfffa","acbhacecd","idhgeiicedjeiebhfff","efbadcffbgcbaefcede","gjhdjjibfea","aehebcjaafbccaj",
        "dfgigcg","jejj","acec","hhbjejfbdbdci","chhijedfgfaihcaibji","e","icjfeigaah","ahjjffhgidb","icfjegaebbjhdaf","fdeeaii","djbdbajjiigifcb",
        "hajdjcjg","bghcefiaf","bd","egigicbehgdfegj","gejebachcbidcgid","afcfdifjgahaddieh","gjfddibcjbgg","bgaeccgfdeghicegb","cjgdjieigbijhacceaj",
        "hcdj","ccedeaffc","bdcdgghehj","hicifijjgecibaheibg","hbahhab","chfdbcdaghf","dgfacjdcfbegjceh","gbaeaddggacdf","icdjaihfidcabfedecff",
        "efjagfhcefdhh","jbgfggjehggefcb","aiejjhcjdife","hj","hefdhcgcbfdcbcaagb","jcbdbdghb","iadib","iaddebggjhcdgaccii","gfehdhbaaahdage",
        "gdhfid","ehhbfgfjcdihhbjjgiii","dcgbbcibidedicfbfe","eadgciaidadeibbcbhj","gabaaice","iahdacfabcgb","dhffdgjbj","jeccccgddcabbaihca",
        "hadacidiajgg","fbeabgcfecb","ebgaefed","gceciecbibc","bhcfdbeccgeaichfgj","bgacgbgih","daegfeaecdiahejaedj","aj","ihjadcdjfec","jh",
        "cchfcegfhhca","gacjcdhafa","becabefhiiifjiebaie","cebjhbhhhh","ddgedfjf","ajgdabhjigibfjf","aefehechbhbeegefjd","cafih","ffeehbgdjicc",
        "hdgaeeefaebjijicjhi","ghbbccibjgddcgaihai","hhbaheb","cfijdeideaihaji","gecicjefbchga","iafbbcjcjhafabea","badifh","gajbbgieajge","jbcg",
        "gedddjchbbeahgb","hcigihiaf","fcfgahjcia","bbhchj","jcabgffgejgajfigb","cjgaddg","dgecgcfejhci","fjabagffj","gacdf","fefichheaehehbeja",
        "fdijhacecbbdfg","ajidh","egjbgfji","hibefecgdeeaaa","eijaahdfbbdgjhchhjjd","gfc" };

bool IsPalindrom(std::string phrase) {
	for (auto i = 0; i < phrase.size() / 2; ++i) {
		if (phrase[i] != phrase[(phrase.size() - 1) - i]) {
			return false;
		}
	}
	return true;
}

std::vector<std::vector<int>> palindromePairs(std::vector<std::string>& words) {
	std::vector<std::vector<int>> res;
	std::vector<int> p;
	for (size_t i = 0; i < words.size() - 1; i++) {
		//cout << i << '\t';
		//LOG_DURATION("palindromePairs duration");
		for (size_t j = i + 1; j < words.size(); j++) {
			/*if (IsPalindrom(words[i] + words[j])) {
				std::vector<int> p; 
				p.push_back(i); 
				p.push_back(j); 
				res.push_back(p); 
				p.clear(); 
			}*/
			if (IsPalindrom(words[j] + words[i]) and IsPalindrom(words[i] + words[j])) {
				//std::vector<int> p; 
				//p.push_back(j); 
				//p.push_back(i); 
				//res.push_back(p); 
				//p.clear(); 
				cout << words[i] << " : " << words[j] << endl;
			}
		}
	}
	return res;
}


/*
A naive approach here would attempt every possible pairing of words, but that would be inefficient. Instead, we can figure out what possible 
words would pair with each word and specifically check for those.
To do this, we'll first have to store each word in a map structure (wmap), with the word as the key and the index as the value. This way, 
we can look up any possible matches with the current word as we iterate through words.
The next thing we'll want to do is define a helper function (isPal) to check if a word is a palindrome. Rather than having to pass it a 
substring of a word, we can define it to take a range of indexes to check, so that we're not constantly building new strings.
As we iterate through words, then, each word will possibly match another word in one of three ways:
    - A blank string word will match on either side with any palindrome word. (e.g. "" will match with "abc" and vice versa)
    - A full word will match on either side with its backwards version. (e.g. "abc" will match with "cba", and vice versa)
    - A partial word will match its backwards version on the opposite side if the leftover portion of the word is a palindrome 
      (e.g. "abcddd" will match with "cba" because "abc" matches with "cba" and "ddd" is a palindrome)
The first check is easy to perform. If we find a blank string, we can iterate through the entire words list an extra time searching for 
palindromes to match. We just need to remember not to match the blank string with itself.
For the second check, since we'll eventually iterate to the matching full word, we should only add the one pair at this time, rather than both, 
as we'll be able to add the second ordering of the same pair when we get to the second word.
The third check is the most difficult. For this, we'll want to first reverse the current word to its backwards version (bw), since we'll be 
matching existing frontwards words in wmap. Then we should iterate through the indexes of the word itself, testing both sides of the dividing 
index (j) for being a palindrome.
If a palindrome is found, then we can attempt to lookup the other portion of the word in wmap. If a match is found, we can push that pair to 
our answer array (ans). At the end of the iteration of words, we can return ans.
Time Complexity: O(N * M^2) where N is the length of words and M is the average length of the words in words
Space Complexity: O(N) for wmap
*/
bool isPal(string& word, int i, int j) {
    while (i < j)
        if (word[i++] != word[j--]) return false;
    return true;
}

vector<vector<int>> palindromePairs(vector<string>& words) {
    std::unordered_map<std::string, int> wmap;
    vector<vector<int>> ans;
    for (int i = 0; i < words.size(); i++)
        wmap[words[i]] = i;
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == "") {
            for (int j = 0; j < words.size(); j++) {
                string& w = words[j];
                if (isPal(w, 0, w.size() - 1) && j != i) {
                    ans.push_back(vector<int> {i, j});
                    ans.push_back(vector<int> {j, i});
                }
            }
            continue;
        }
        string bw = words[i];
        reverse(bw.begin(), bw.end());
        if (wmap.find(bw) != wmap.end()) {
            int res = wmap[bw];
            if (res != i) ans.push_back(vector<int> {i, res});
        }
        for (int j = 1; j < bw.size(); j++) {
            if (isPal(bw, 0, j - 1)) {
                string s = bw.substr(j, bw.size() - j);
                if (wmap.find(s) != wmap.end())
                    ans.push_back(vector<int> {i, wmap[s]});
            }
            if (isPal(bw, j, bw.size() - 1)) {
                string s = bw.substr(0, j);
                if (wmap.find(s) != wmap.end())
                    ans.push_back(vector<int> {wmap[s], i});
            }
        }
    }
    return ans;
}


    