/* ////////// LICENSE INFO ////////////////////

 * Copyright (C) 2013 by NYSOL CORPORATION
 *
 * Unless you have received this program directly from NYSOL pursuant
 * to the terms of a commercial license agreement with NYSOL, then
 * this program is licensed to you under the terms of the GNU Affero General
 * Public License (AGPL) as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THOSE OF 
 * NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Please refer to the AGPL (http://www.gnu.org/licenses/agpl-3.0.txt)
 * for more details.

 ////////// LICENSE INFO ////////////////////*/
// ============================================================================
// kgWildcard.cpp : ファイルカードクラス
// ============================================================================
#include <kgWildcard.h>
#include <kgMethod.h>

using namespace std;
using namespace kglib;

// -----------------------------------------------------------------------------
// コンストラクタ
// -----------------------------------------------------------------------------
kgWildCard::kgWildCard(const kgstr_t& pat)
{
	_pat=pat;
  _patLen = pat.length();
	if( _patLen> KG_MAX_STR_LEN ){ throw kgError("too long wildcard"); }
	_hasWildCard=false;
  for(string::size_type i=0; i<_patLen; i++){
    if (_pat[i] == '*' || _pat[i] == '?'){
			_wildc[i] = _pat[i];
			_hasWildCard=true;
		}else{
			_wildc[i] = ' ';
		}
  }
}
// -----------------------------------------------------------------------------
// txtがワイルドカードにマッチすればtrueを返す
// -----------------------------------------------------------------------------
bool kgWildCard::match(const kgstr_t& txt)
{
  // FSAの初期化
	_state[0] = true;
	for (string::size_type i = 1; i <= _patLen; i++) {
		_state[i] = false;
	}

  // 必要なサイズ
  string::size_type txtLen = txt.length();
	if( txtLen> KG_MAX_STR_LEN ){ throw kgError("too long text"); }

  // patter マッチ
  for (string::size_type i = 0; i <= txtLen; i++) {
    // epsilon transition
    for (string::size_type j = 0; j < _patLen; j++) {
      if (_state[j] && _wildc[j] == '*'){ _state[j+1] = true; }
    }
    if (i == txtLen){ break; }// epsilon transitionのみ一度多い
    _state[_patLen] = false;       // ゴール地点をクリア

    // 入力とのマッチによる遷移
    for (int j = _patLen-1; j >= 0; j--) {
     if (_state[j]) {
        switch (_wildc[j]) {
        case ' ': // 通常の文字
          if(_pat[j] == txt[i]){  _state[j+1] = true; }
          _state[j] = false;
          break;
        case '*': // *はなにもしない(epsilon transitionでおこなう)
          break;
        case '?': // ？は無条件にひとつ進める
          _state[j+1] = true;
          _state[j] = false;
          break;
        }
      }
    }
  }
	// 判定は最終位置のチェック
	return _state[_patLen];
}

