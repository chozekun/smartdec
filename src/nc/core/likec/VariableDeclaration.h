/* * SmartDec decompiler - SmartDec is a native code to C/C++ decompiler
 * Copyright (C) 2015 Alexander Chernov, Katerina Troshina, Yegor Derevenets,
 * Alexander Fokin, Sergey Levin, Leonid Tsvetkov
 *
 * This file is part of SmartDec decompiler.
 *
 * SmartDec decompiler is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * SmartDec decompiler is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with SmartDec decompiler.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <nc/config.h>

#include "Commentable.h"
#include "Declaration.h"

namespace nc {
namespace core {
namespace likec {

class Type;

/**
 * Variable declaration.
 */
class VariableDeclaration: public Declaration, public Commentable {
    const Type *type_; ///< Type of this variable.

public:
    /**
     * Class constructor.
     *
     * \param[in] tree Owning tree.
     * \param[in] identifier Name of this variable.
     * \param[in] type Type of this variable.
     */
    VariableDeclaration(Tree &tree, const QString &identifier, const Type *type):
        Declaration(tree, VARIABLE_DECLARATION, identifier), type_(type)
    {}

    /**
     * \return Type of this variable.
     */
    const Type *type() const { return type_; }

    virtual VariableDeclaration *rewrite() override { return this; }

    virtual void doPrint(PrintContext &context) const override;
};

} // namespace likec
} // namespace core
} // namespace nc

NC_REGISTER_CLASS_KIND(nc::core::likec::Declaration, nc::core::likec::VariableDeclaration, nc::core::likec::Declaration::VARIABLE_DECLARATION)

/* vim:set et sts=4 sw=4: */
