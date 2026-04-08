#include <hyprtoolkit/backend/CBackend.hpp>
#include <hyprtoolkit/windows/CWindow.hpp>
#include <hyprtoolkit/elements/CRectangle.hpp>
#include <hyprtoolkit/elements/CText.hpp>
#include <hyprtoolkit/elements/CLayout.hpp>
#include <memory>

using namespace Hyprtoolkit;

auto backend = CBackend::Create();
auto window = CWindowBuilder::begin()->appTitle("Hello")->appClass("hyprtoolkit")->commence();

int main() {
    window->m_rootElement->addChild(CRectangleBuilder::begin()->color([] { return backend->getPalette()->m_colors.background; })->commence());

}
