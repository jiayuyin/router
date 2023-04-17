enum {
    POLICY_ATTR_NAME,       /** name */
    POLICY_ATTR_ENABLE,     /** enable */
    POLICY_ATTR_DNS,        /** dns */
    __POLICY_ATTR_MAX
};
 
static const struct blobmsg_policy policy_attrs[__POLICY_ATTR_MAX] = {
    [POLICY_ATTR_NAME] = { .name = "name", .type = BLOBMSG_TYPE_STRING },
    [POLICY_ATTR_ENABLE] = { .name = "enable", .type = BLOBMSG_TYPE_BOOL },
    [POLICY_ATTR_DNS] = { .name = "dns", .type = BLOBMSG_TYPE_ARRAY },
};
 
/** 定义BLOBMSG_TYPE_ARRAY类型参数的实际数据类型 */
static const struct uci_blob_param_info policy_attr_info[__POLICY_ATTR_MAX] = {
    [POLICY_ATTR_DNS] = { .type = BLOBMSG_TYPE_STRING },
};
 
static const struct uci_blob_param_list policy_attr_list = {
    .n_params = __POLICY_ATTR_MAX,
    .params = policy_attrs,
    .info = policy_attr_info,
};

static struct uci_context *g_uci_ctx;
static struct blob_buf *b;
 
void
transform(const char *config)
{
    struct uci_context *ctx = g_uci_ctx;
    struct uci_package *p = NULL;
 
    if (!ctx) {
        ctx = uci_alloc_context();
        g_uci_ctx = ctx;
        uci_set_confdir(ctx, NULL);
    } else {
        p = uci_lookup_package(ctx, config);
        if (p)
            uci_unload(ctx, p);
    }
 
    if (uci_load(ctx, config, &p))
        return;    
 
    struct uci_element *e;
    struct blob_attr *config = NULL;
    uci_foreach_element(&p->sectons, e) {
        struct uci_section *s = uci_to_section(e);
 
        blob_buf_init(&b, 0);
        uci_to_blob(&b, s, &policy_attr_list);
        config = blob_memdup(b.head);
 
        /**
         * do something with `config` 
         * free(config), when not use it
         */
    }
}

void
foo(blob_attr *confg)
{
    struct blob_attr *tb[__POLICY_ATTR_MAX];
 
    blobmsg_parse(policy_attrs, __POLICY_ATTR_MAX, tb,
            blob_data(config), blob_len(config));
 
    /**
     * do something with *tb[] 
     */
}