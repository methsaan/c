#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *substring(char *string, int position, int length) {
	char *pointer;
	int c;
	pointer = malloc(length+1);
	if (pointer == NULL) {
		printf("Unable to allocate memory.\n");
		exit(1);
	}
	for (c = 0 ; c < length ; c++) {
		*(pointer+c) = *(string+position);      
		string++;  
	}
	*(pointer+c) = '\0';
	return pointer;
}

int main(int argc, char *argv[]) {
	char *words[] = {"aa", "ab", "ad", "ae", "ag", "ah", "ai", "al", "am", "an", "ar", "as", "at", "aw", "ax", "ay", "ba", "be", "bi", "bo", "by", "ch", "da", "de", "di", "do", "ea", "ed", "ee", "ef", "eh", "el", "em", "en", "er", "es", "et", "ex", "fa", "fe", "fy", "gi", "go", "gu", "ha", "he", "hi", "hm", "ho", "id", "if", "in", "io", "is", "it", "ja", "jo", "ka", "ki", "ko", "ky", "la", "li", "lo", "ma", "me", "mi", "mm", "mo", "mu", "my", "na", "ne", "no", "nu", "ny", "ob", "od", "oe", "of", "oi", "om", "on", "oo", "op", "or", "os", "ou", "ow", "ox", "oy", "pa", "pe", "pi", "po", "qi", "re", "sh", "si", "so", "st", "ta", "te", "ti", "to", "ug", "uh", "um", "un", "up", "ur", "us", "ut", "we", "wo", "xi", "xu", "ya", "ye", "yo", "yu", "za", "zo", "aah", "aal", "aas", "aba", "abo", "abs", "aby", "ace", "act", "add", "ado", "ads", "adz", "aff", "aft", "aga", "age", "ago", "ags", "aha", "ahi", "ahs", "aid", "ail", "aim", "ain", "air", "ais", "ait", "ala", "alb", "ale", "all", "alp", "als", "alt", "ama", "ami", "amp", "amu", "ana", "and", "ane", "annie", "ant", "any", "ape", "apo", "app", "apt", "arb", "arc", "are", "arf", "ark", "arm", "ars", "art", "ash", "ask", "asp", "ass", "ate", "att", "auk", "ava", "ave", "avo", "awa", "awe", "awl", "awn", "axe", "aye", "ays", "azo", "baa", "bad", "bag", "bah", "bal", "bam", "ban", "bap", "bar", "bas", "bat", "bay", "bed", "bee", "beg", "bel", "ben", "bes", "bet", "bey", "bib", "bid", "big", "bin", "bio", "bis", "bit", "biz", "boa", "bob", "bod", "bog", "boo", "bop", "bos", "bot", "bow", "box", "boy", "bra", "bro", "brr", "bub", "bud", "bug", "bum", "bun", "bur", "bus", "but", "buy", "bye", "bys", "cab", "cad", "cam", "can", "cap", "car", "cat", "caw", "cay", "cee", "cel", "cep", "chi", "cig", "cis", "cob", "cod", "cog", "col", "con", "coo", "cop", "cor", "cos", "cot", "cow", "cox", "coy", "coz", "cru", "cry", "cub", "cud", "cue", "cum", "cup", "cur", "cut", "cwm", "dab", "dad", "dag", "dah", "dak", "dal", "dam", "dan", "dap", "daw", "day", "deb", "dee", "def", "del", "den", "dev", "dew", "dex", "dey", "dib", "did", "die", "dif", "dig", "dim", "din", "dip", "dis", "dit", "doc", "doe", "dog", "dol", "dom", "don", "dor", "dos", "dot", "dow", "dry", "dub", "dud", "due", "dug", "duh", "dui", "dun", "duo", "dup", "dye", "ear", "eat", "eau", "ebb", "ecu", "edh", "eds", "eek", "eel", "eff", "efs", "eft", "egg", "ego", "eke", "eld", "elf", "elk", "ell", "elm", "els", "eme", "ems", "emu", "end", "eng", "ens", "eon", "era", "ere", "erg", "ern", "err", "ers", "ess", "eta", "eth", "eve", "ewe", "eye", "fab", "fad", "fag", "fan", "far", "fas", "fat", "fax", "fay", "fed", "fee", "feh", "fem", "fen", "fer", "fes", "fet", "feu", "few", "fey", "fez", "fib", "fid", "fie", "fig", "fil", "fin", "fir", "fit", "fix", "fiz", "flu", "fly", "fob", "foe", "fog", "foh", "fon", "fop", "for", "fou", "fox", "foy", "fro", "fry", "fub", "fud", "fug", "fun", "fur", "gab", "gad", "gae", "gag", "gal", "gam", "gan", "gap", "gar", "gas", "gat"};
	char *rhymingwords[600];
	char *word;
	word = argv[1];
	int cnt = 0;
	for (int x = 0; x < sizeof(words)/sizeof(*words); x++) {
		char *wordend1;
		wordend1 = substring(word, 1, strlen(word)-1);
		char *wordend2;
		wordend2 = substring(words[x], 1, strlen(words[x])-1);
		if (strcmp(words[x], word) != 0 && strcmp(wordend1, wordend2) == 0) {
			rhymingwords[cnt] = words[x];
			cnt++;
		}
		
	}
	printf("Rhyming words for %s:\n", word);
	for (int x = 0; x < cnt; x++) {
		printf("%s\n", rhymingwords[x]);
	}
}
