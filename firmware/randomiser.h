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

    /**
     * Returns a random number in the range [0, max]
     * The returned value will not be repeated until at least
     * AVOID_REPEAT_RANDOM calls.
     */
    int random(int max) const;

    /**
     * Returns true or false randomly
     */
    bool coinFlip() const;


private:
    bool entryInLastEntries(int entry) const;

    mutable int lastEntries[AVOID_REPEAT_RANDOM];
    mutable int lastEntryIndex;
};

#endif // _RANDOMISER_H_
