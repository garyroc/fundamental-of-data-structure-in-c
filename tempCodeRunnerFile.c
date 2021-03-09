
        /* no warp around*/
        copy(queue + start,queue + start + capacity -1,newQueue);

    else
    {/* queue warps around*/
        copy(queue + start, queue + capacity, newQueue + capacity + start);
        copy(queue, queue + rear + 1, newQueue);
        copy(newQueue, newQueue + rear + 1, newQueue + rear + 2);
        copy(newQueue + capacity + start, newQueue + 2 * capacity, newQueue);
    }

    /* switch to newQueue */