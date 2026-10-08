; Include under entities section in entity.set at the last line
; Including code:
; (include "custom/reverse.inc")
{"vehicle"
	{on "reverse"
        {if tagged "reversed"
            {tags add "remove_reverse"}
            {tags remove "reversed"}
        else
            {tags add "reverse"}
        }
    }
}
