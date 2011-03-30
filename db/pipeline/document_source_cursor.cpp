/**
 * Copyright 2011 (c) 10gen Inc.
 *
 * This program is free software: you can redistribute it and/or  modify
 * it under the terms of the GNU Affero General Public License, version 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "pch.h"

#include "db/pipeline/document_source.h"

#include "db/Cursor.h"
#include "db/pipeline/document.h"
#include "db/pipeline/expression.h"

namespace mongo {
    DocumentSourceCursor::DocumentSourceCursor(shared_ptr<Cursor> pTheCursor):
        pCursor(pTheCursor) {
    }

    bool DocumentSourceCursor::eof() {
        return pCursor->eof();
    }

    bool DocumentSourceCursor::advance() {
        return pCursor->advance();
    }

    shared_ptr<Document> DocumentSourceCursor::getCurrent() {
        BSONObj documentObj(pCursor->current());
        shared_ptr<Document> pDocument(
            Document::createFromBsonObj(&documentObj));
        return pDocument;
    }

    DocumentSourceCursor::~DocumentSourceCursor() {
    }
}