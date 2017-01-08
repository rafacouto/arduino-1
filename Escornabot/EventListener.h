// EventListener.h
/*

Copyright (C) 2014-2017 Escornabot - http://escornabot.com

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
USA.

See LICENSE.txt for details

*/

#ifndef _EVENT_LISTENER_H
#define _EVENT_LISTENER_H

#include <stddef.h>
#include "Enums.h"


/**
 * \brief Abstract event listener to be implemented by listeners.
 * \author @caligari
 */
class EventListener
{

public:

    EventListener()
    {
        this->_next = NULL;
    }

    EventListener* getNext()
    {
        return this->_next;
    }

    void setNext(EventListener* value)
    {
        this->_next = value;
    }

    //////////////////////////////////////////////////////////////////////
    // public interface
    //////////////////////////////////////////////////////////////////////

    virtual bool tick(uint32_t micros) { return false; }

    /**
     * Handles when a movement from the program has started its execution.
     * @param move The movement.
     */
    virtual bool moveExecuting(MOVE move) { return false; }

    /**
     * Handles when a movement from the program has finished its execution.
     * @param move The movement.
     */
    virtual bool moveExecuted(MOVE move) { return false; }

    /**
     * Handles when a new movement was added to the program.
     * @param move The movement.
     */
    virtual bool moveAdded(MOVE move) { return false; }

    /**
     * Handles when the program has started.
     * @param total_moves Total moves in the program.
     */
    virtual bool programStarted(uint8_t total_moves) { return false; }

    /**
     * Handles when the program has finished.
     */
    virtual bool programFinished() { return false; }

    /**
     * Handles when the program has reset.
     */
    virtual bool programReset() { return false; }

    /**
     * Handles when the program was aborted.
     * @param executed Number of executed moves after aborted.
     * @param total Total moves in the program.
     */
    virtual bool programAborted(uint8_t executed, uint8_t total) { return false; }

    /**
     * Handles when a button was pressed.
     * @param button The button.
     */
    virtual bool buttonPressed(BUTTON button) { return false; }

    /**
     * Handles when a button was released.
     * @param button The button.
     */
    virtual bool buttonReleased(BUTTON button) { return false; }

    /**
     * Handles when a button was long released.
     * @param button The button.
     */
    virtual bool buttonLongReleased(BUTTON button) { return false; }

private:

    EventListener* _next;
};

#endif //  _EVENT_LISTENER_H

// EOF
