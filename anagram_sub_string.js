let w = 'abx'; // The word to check for anagrams
let S = 'abxaba'; // The string to search in

let holdWords = S.split(""); // Split the string into characters
let anagramIndices = []; // Store the indices of found anagrams

// Function to check for anagrams
for(let i = 0; i <= holdWords.length - w.length; i++) {
    let currWord = holdWords.slice(i, i + w.length).join(""); // Extract a slice of the string
    
    // Check if the current slice is an anagram of the word 'w'
    if(currWord.split("").sort().join("") === w.split("").sort().join("")) {
        console.log("Anagram found:", currWord, "at index:", i);
        anagramIndices.push(i); // Store the index where the anagram is found
    }
}

// Print all indices where anagrams were found
if(anagramIndices.length > 0) {
    console.log("\nTotal anagrams found:", anagramIndices.length);
    console.log("Anagram indices:", anagramIndices);
} else {
    console.log("No anagrams found.");
}

// Function to print the anagrams at each index
function printAnagrams() {
    if(anagramIndices.length > 0) {
        console.log("\nAnagrams found at the following indices:");
        anagramIndices.forEach(index => {
            let anagram = holdWords.slice(index, index + w.length).join("");
            console.log(`Index: ${index}, Anagram: ${anagram}`);
        });
    }
}

// Call the function to display anagrams
printAnagrams();
