#pragma once
#ifndef WRITER_H
#define WRITER_H

/**
 * Abstract base class (interface) for objects that write their contents
 * to something.
 */
template <typename T>
class Writer {
public:
    /**
     * Sets the writable contents of this object.
     * @param Contents to write.
     */
    virtual void setContents (T contents) = 0;

    /**
     * Writes the contents of this object.
     */
    virtual void write () = 0;
};

#endif // WRITER_H
