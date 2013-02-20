/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010- Facebook, Inc. (http://www.facebook.com)         |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#include <runtime/base/util/curl_tls_workarounds.h>
#include <runtime/base/runtime_option.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <openssl/ssl.h>

namespace HPHP {

CURLcode curl_tls_workarounds_cb(CURL *curl, void *sslctx, void *parm) {
  // Check to see if workarounds are enabled.
  if (RuntimeOption::TLSDisableTLS1_2) {
    SSL_CTX* ctx = (SSL_CTX*)sslctx;
    SSL_CTX_set_options(ctx, SSL_CTX_get_options (ctx) | SSL_OP_NO_TLSv1_2);
  }
  return CURLE_OK;
}

}