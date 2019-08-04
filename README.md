Floyd's loop detection and loop removal algorithm using C language:

Before trying to remove the loop, we must detect it. Technique that I have used
here can be used to detect loop. To remove loop, all we need to do is to
get pointer to the last node of the loop. Once we have pointer to the last node,
we can make the link of this node as NULL and loop is gone.
