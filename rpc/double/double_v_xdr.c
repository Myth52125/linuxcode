/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "double_v.h"

bool_t
xdr_double_in (XDR *xdrs, double_in *objp)
{
	register int32_t *buf;

	 if (!xdr_long (xdrs, &objp->key))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_double_out (XDR *xdrs, double_out *objp)
{
	register int32_t *buf;

	 if (!xdr_long (xdrs, &objp->value))
		 return FALSE;
	return TRUE;
}
