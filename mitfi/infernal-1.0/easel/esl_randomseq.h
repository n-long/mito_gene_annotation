/* Generating, shuffling, and randomizing sequences.
 * 
 * SRE, Thu Apr 24 09:38:13 2008 [Janelia]
 * SVN $Id$
 */
#ifndef ESL_RANDOMSEQ_INCLUDED
#define ESL_RANDOMSEQ_INCLUDED

#include "esl_random.h"

/* 1. Generating iid sequences. */
extern int esl_rsq_IID  (ESL_RANDOMNESS *r, const char *alphabet, const double *p, int K, int L, char *s);
extern int esl_rsq_fIID (ESL_RANDOMNESS *r, const char *alphabet, const float  *p, int K, int L, char *s);

/* 2. Shuffling sequences. */
extern int esl_rsq_CShuffle  (ESL_RANDOMNESS *r, const char *s, char *shuffled);
extern int esl_rsq_CShuffleDP(ESL_RANDOMNESS *r, const char *s, char *shuffled);
extern int esl_rsq_CReverse  (const char *s, char *rev);
extern int esl_rsq_CShuffleWindows(ESL_RANDOMNESS *r, const char *s, int w, char *shuffled);

/* 3. Randomizing sequences */
extern int esl_rsq_CMarkov0  (ESL_RANDOMNESS *r, const char *s, char *markoved);
extern int esl_rsq_CMarkov1  (ESL_RANDOMNESS *r, const char *s, char *markoved);

/* 4. Generating iid sequences (digital mode). */
extern int esl_rsq_xIID (ESL_RANDOMNESS *r, const double *p, int K, int L, ESL_DSQ *dsq);
extern int esl_rsq_xfIID(ESL_RANDOMNESS *r, const float  *p, int K, int L, ESL_DSQ *dsq);

/* 5. Shuffling sequences (digital mode). */
extern int esl_rsq_XShuffle  (ESL_RANDOMNESS *r, const ESL_DSQ *dsq, int L, ESL_DSQ *shuffled);
extern int esl_rsq_XShuffleDP(ESL_RANDOMNESS *r, const ESL_DSQ *dsq, int L, int K, ESL_DSQ *shuffled);
extern int esl_rsq_XReverse(const ESL_DSQ *dsq, int L, ESL_DSQ *rev);
extern int esl_rsq_XShuffleWindows(ESL_RANDOMNESS *r, const ESL_DSQ *s, int L, int w, ESL_DSQ *shuffled);

/* 6. Randomizing sequences (digital mode) */
extern int esl_rsq_XMarkov0  (ESL_RANDOMNESS *r, const ESL_DSQ *dsq, int L, int K, ESL_DSQ *markoved);
extern int esl_rsq_XMarkov1  (ESL_RANDOMNESS *r, const ESL_DSQ *dsq, int L, int K, ESL_DSQ *markoved);

#endif /*ESL_RANDOMSEQ_INCLUDED*/

/*****************************************************************
 *    This copyrighted source code is freely distributed 
 *    under the terms of the GNU General Public License. See
 *    the files COPYRIGHT and LICENSE for details.
 *****************************************************************/

