#include "data.h"
#include <string.h>

Data::Data()
{
    countObliqueEntries();
}


const char * Data::getRandomEntry() const
{


    return 0;
}

const char * Data::getRandomUserEntry(bool deleteEntry)
{
    return 0;
}

bool Data::addUserEntry(const char* entry)
{
    if (strlen(entry) >= MAX_USER_ENTRY_LENGTH) {
        return false;
    }
    // TODO
    char* target_entry = user_entries[0];
    strcpy(target_entry, entry);

    return true;
}

void Data::countObliqueEntries()
{
    obliqueCount = 0;
    while(oblique_entries[obliqueCount]) {
        obliqueCount++;
    }
}

int Data::obliqueCount = 0;

char Data::user_entries[MAX_USER_ENTRIES][MAX_USER_ENTRY_LENGTH] = {0};

const char * const Data::oblique_entries[] = {
	"Abandon desire",
	"Abandon normal instructions",
	"Accept advice",
	"Adding on",
	"A line has two sides",
	"Always the first steps",
	"Ask people to work against their better judgement",
	"Ask your body",
	"Be dirty",
	"Be extravagant",
	"Be less critical",
	"Breathe more deeply",
	"Bridges -build -burn",
	"Change ambiguities to specifics",
	"Change nothing and continue consistently",
	"Change specifics to ambiguities",
	"Consider transitions",
	"Courage!",
	"Cut a vital connection",
	"Decorate, decorate",
	"Destroy nothing; Destroy the most important thing",
	"Discard an axiom",
	"Disciplined self-indulgence",
	"Discover your formulas and abandon them",
	"Display your talent",
	"Distort time",
	"Do nothing for as long as possible",
	"Don't avoid what is easy",
	"Don't break the silence",
	"Don't stress one thing more than another",
	"Do something boring",
	"Do something sudden, destructive and unpredictable",
	"Do the last thing first",
	"Do the words need changing?",
	"Emphasize differences",
	"Emphasize the flaws",
	"Faced with a choice, do both",
	"Find a safe part and use it as an anchor",
	"Give the game away",
	"Give way to your worst impulse",
	"Go outside. Shut the door.",
	"Go to an extreme, come part way back",
	"How would someone else do it?",
	"How would you have done it?",
	"In total darkness, or in a very large room, very quietly",
	"Is it finished?",
	"Is something missing?",
	"Is the style right?",
	"It is simply a matter or work",
	"Just carry on",
	"Listen to the quiet voice",
	"Look at the order in which you do things",
	"Magnify the most difficult details",
	"Make it more sensual",
	"Make what's perfect more human",
	"Move towards the unimportant",
	"Not building a wall; making a brick",
	"Once the search has begun, something will be found",
	"Only a part, not the whole",
	"Only one element of each kind",
	"Openly resist change",
	"Pae White's non-blank graphic metacard",
	"Question the heroic",
	"Remember quiet evenings",
	"Remove a restriction",
	"Repetition is a form of change",
	"Retrace your steps",
	"Reverse",
	"Simple Subtraction",
	"Slow preparation, fast execution",
	"State the problem as clearly as possible",
	"Take a break",
	"Take away the important parts",
	"The inconsistency principle",
	"The most easily forgotten thing is the most important",
	"Think - inside the work -outside the work",
	"Tidy up",
	"Try faking it",
	"Turn it upside down",
	"Use an old idea",
	"Use cliches",
	"Use filters",
	"Use something nearby as a model",
	"Use 'unqualified' people",
	"Use your own ideas",
	"Voice your suspicions",
	"Water",
	"What context would look right?",
	"What is the simplest solution?",
	"What mistakes did you make last time?",
	"What to increase? What to reduce? What to maintain?",
	"What were you really thinking about just now?",
	"What wouldn't you do?",
	"What would your closest friend do?",
	"When is it for?",
	"Where is the edge?",
	"Which parts can be grouped?",
	"Work at a different speed",
	"Would anyone want it?",
	"Your mistake was a hidden intention",
	// Diary entries
	"Steal a solution",
    "Describe the landscape in which this belongs",
    "What else is this like?",
    "List the qualities it has.\nList those you'd like.",
    "Instead of changing the thing,\nchange the world around it.",
    "What would make this really successful?",
    "Who would make this really successful?",
    "How would you explain this to your parents?",
    "What were the branch points in\nthe evolution of this entity?",
    "Back up a few steps.\nWhat else could you have done?",
    "When is it for?\nWho is it for?",
    "What do you do?\nNow, what do you do best?",
    "First work alone, then work in unusual pairs.",
    "What most recently impressed you?\nHow is it similar?\nWhat can you learn from it?\nWhat could you take from it?",
    "Take away as much mystery as possible.\nWhat is left?",
	0
	};
