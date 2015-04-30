#ifndef _RANDOMISER_H_
#define _RANDOMISER_H_

#define AVOID_REPEAT_RANDOM 20

/**
 * Provides random numbers that aren't too likely to repeat
 * (at least AVOID_REPEAT_RANDOM calls before a number repeats)
 */
class Randomiser
{
public:
    Randomiser();
    int random(int max);

private:
    bool entryInLastEntries(int entry);

    int lastEntries[AVOID_REPEAT_RANDOM];
    int lastEntryIndex;
};

#endif // _RANDOMISER_H_
