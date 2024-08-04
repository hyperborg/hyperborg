#ifndef SEQUENCER_H
#define SEQUENCER_H

#include "common.h"

=================== GLOBAL SEQENCE PROVIDER FOR GENERATING IDs (singleton)  =============================== */
class Sequencer
{
public:
    static Sequencer& getInstance()
    {
        static Sequencer instance;
        return instance;
    }

    Sequencer(Sequencer const&) = delete;
    void operator=(Sequencer const&) = delete;
    int getNextVal()
    {
        return _cnt++;
    }

    int setTop(int val)
    {
        if (val>_cnt)

            _cnt=val+1;
        return _cnt;
    }

private:
    Sequencer()
    {
        _cnt = 0;
    }
    int _cnt;
};

#define SEQ_NEXTVAL Sequencer::getInstance().getNextVal()

#endif
