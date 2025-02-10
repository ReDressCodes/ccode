char_lower <- c('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k','l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z');

char_upper <- c('A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z');

to_upper <- function (to_convert) {
	count <- 0;

	for (char in char_lower) { 
	    if (char == to_convert) {
	        to_convert <- char_upper[count + 1];
	    }
	    else
	    {
		count = count + 1
	    }
	}

	to_convert;
}

to_lower <- function(to_convert) {
	count <- 0;

	for (char in char_upper) { 
	    if (char == to_convert) {
	        to_convert <- char_lower[count + 1];
	    }
	    else
	    {
		count = count + 1
	    }
	}

	to_convert;
}

lower_char = 'a';
upper_char = 'X';

print(to_upper(lower_char));
print(to_lower(upper_char));

