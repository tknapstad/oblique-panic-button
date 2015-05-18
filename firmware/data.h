#ifndef _DATA_H_
#define _DATA_H_

#define MAX_USER_ENTRIES         32
#define MAX_USER_ENTRY_LENGTH   120

#include "randomiser.h"
#include <stdint.h>

class Data
{
public:
    Data();

    /**
     * Return a random entry.
     */
    const char * getRandomEntry() const;

    /**
     * Returns a random user entry and deletes it if delete is true.
     * Returns NULL if no user entry exists
     */
    const char * getRandomUserEntry(bool deleteEntry);

    /**
     * Adds a user entry. Returns false if \entry exceeds MAX_USER_ENTRY_LENGTH.
     * If MAX_USER_ENTRIES has been reached, the oldest entry is deleted.
     */
    bool addUserEntry(const char* entry);

private:
    uint16_t countObliqueEntries() const;

    static char user_entries[MAX_USER_ENTRIES][MAX_USER_ENTRY_LENGTH];
    static const char * const oblique_entries[];

    const uint16_t obliqueCount;
    Randomiser rnd;
};

#endif // _DATA_H_
