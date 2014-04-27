#pragma once
#ifndef READER_H
#define READER_H

/**
 * Pure abstract base class (interface) for objects that read something.
 */
template <typename T>
class Reader {
public:
  /**
   * Reads something.
   * @return Whatever is read.
   */
  virtual T read () = 0;
};

#endif // READER_H
