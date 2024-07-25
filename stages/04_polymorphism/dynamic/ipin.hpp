#pragma once

class IPin {
public:
    virtual void set () = 0;
    virtual void reset () = 0;
};