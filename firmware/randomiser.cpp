#include "randomiser.h"
#include <string.h>

Randomiser::Randomiser()
    : lastEntryIndex(0)
{
    memset(lastEntries, -1, AVOID_REPEAT_RANDOM * sizeof(int));
}

int Randomiser::random(int max) const
{
    int entry = -1;
    do
    {
        entry = random(max);
    } while(!entryInLastEntries(entry));

    lastEntries[lastEntryIndex] = entry;
    lastEntryIndex = (lastEntryIndex + 1) % AVOID_REPEAT_RANDOM;

    return entry;
}

bool Randomiser::coinFlip() const
{
    return random(2);
}

bool Randomiser::entryInLastEntries(int entry) const
{
    for(int i = 0; i < AVOID_REPEAT_RANDOM; i++)
    {
        if (entry == lastEntries[i]) {
            return true;
        }
    }

    return false;
}
