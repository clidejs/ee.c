/* ee - eventemitter for c - ee-test.c
 * https://github.com/clidejs/ee.c
 *
 * Copyright Bernhard Bücherl <bernhard.buecherl@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include "ee.h"
#include "ee.c"
#include <iostream>

#define EVENT_NAME 1

void callback(void *ptr) {
  std::cout << ptr << std::endl;
}
int main() {
  ee_emitter_t *ee =(ee_emitter_t *)malloc(sizeof(ee_emitter_t));
  ee_init(ee);

  ee_on(ee, EVENT_NAME, callback);

  ee_emit(ee, EVENT_NAME, 0);

  ee_off(ee, EVENT_NAME, callback);

  ee_emit(ee, EVENT_NAME, 0);

  ee_destroy(ee);
  return 0;
}
