/**************************************************************************/
/*  material_x_3d.h                                                       */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef MATERIAL_X_3D_H
#define MATERIAL_X_3D_H

#include "MaterialXCore/Generated.h"

#include "core/io/resource_importer.h"
#include "scene/resources/material.h"
#include "scene/resources/visual_shader.h"

#include <MaterialXCore/Util.h>
#include <MaterialXFormat/Util.h>
#include <MaterialXGenGlsl/EsslShaderGenerator.h>

#include <iostream>
#include <map>

using namespace godot;
namespace mx = MaterialX;
class MTLXLoader : public Resource {
	GDCLASS(MTLXLoader, Resource);
	void process_node_graph(mx::DocumentPtr doc, Ref<VisualShader> shader) const;
	void process_node(const mx::NodePtr &node, Ref<VisualShader> shader, int node_i) const;
	void add_input_port(mx::InputPtr input, Ref<VisualShaderNodeExpression> expression_node, int input_port_i) const;
	void add_output_port(mx::OutputPtr output, Ref<VisualShaderNodeExpression> expression_node) const;
	static Variant get_value_as_variant(const mx::ValuePtr &value);

protected:
	static void _bind_methods();

public:
	virtual Variant _load(const String &p_save_path, const String &p_original_path, bool p_use_sub_threads, int64_t p_cache_mode) const;
	MTLXLoader() {
	}
};
using MaterialPtr = std::shared_ptr<class Material>;

#endif // MATERIAL_X_3D_H